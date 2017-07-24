#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <unistd.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <error.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#define SERVER_PORT 8888

void sig_chld(int sig)  
{  
	pid_t pid;  
	int stat;  
	while((pid = waitpid(-1,&stat,WNOHANG))>0)
		printf("chlid %d exitd\n", pid);
	return;  
}  
int main(int argc, char * args[])
{
	int serfd;//服务端套接字
	struct sockaddr_in ser_add,cli_add;
	int addrlen = sizeof(cli_add);
	int client;
	char buf[1024];
	int idatanum;

	if((serfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket error");
		return 1;
	}

	bzero(&ser_add, sizeof(ser_add));
	memset(buf, 0 ,sizeof(buf));
	/* struct sockaddr */  
	/* { */  
	/* //地址族，2字节 */  
	/* unsigned short sa_family; */  
	/* //存放地址和端口，14字节 */  
	/* char sa_data[14]; */  
	/* } */  
	/* struct in_addr { */
	/*     in_addr_t s_addr; */
	/* }; */
	/* struct sockaddr_in */  
	/* { */  
	/* //地址族 */  
	/* short int sin_family; */  
	/* //端口号(使用网络字节序) */  
	/* unsigned short int sin_port; */  
	/* //地址 */  
	/* struct in_addr sin_addr; */  
	/* //8字节数组，全为0，该字节数组的作用只是为了让两种数据结构大小相同而保留的空字节 */  
	/* unsigned char sin_zero[8] */  
	/* } */  

	ser_add.sin_family = AF_INET;
	ser_add.sin_addr.s_addr = htonl(INADDR_ANY);
	ser_add.sin_port = htons(SERVER_PORT);

	if(bind(serfd, (struct sockaddr *)&ser_add, sizeof(ser_add)) < 0)
	{
		perror("bind error");
		return 2;
	}

	if(listen(serfd, 5) < 0)
	{
		perror("listen error");
		return 3;
	}

	int pid;
	signal(SIGCHLD,sig_chld);
	while(1)
	{
		printf("listen to port:%d\n", SERVER_PORT);
		client = accept(serfd, (struct sockaddr *)&cli_add, (socklen_t *)&addrlen);
		if(client < 0)
		{
			perror("accrpt error");
			return 4;
		}
		int pid = fork();
		if(pid < 0 )
		{
			perror("fork error");
			return 6;
		}
		if(pid == 0)
		{
			printf("子进程开始执行");
			close(serfd);//子进程关闭监听
			printf("in child pid %d\n", getpid());
			printf("IP is %s\n", inet_ntoa(cli_add.sin_addr));  
			printf("Port is %d\n", htons(cli_add.sin_port));
			while(1)
			{
				memset(buf, 0 ,sizeof(buf));
				idatanum = recv(client, buf, 1024, 0);
				if(idatanum <= 0)//客户端关闭连接时为0
				{
					close(client);
					perror("recv error");
					break;
				}
				buf[idatanum] = '\0';
				printf("%d recv data is %s\n", idatanum, buf);
				send(client, buf, idatanum, 0);
			}
			printf("子进程关闭连接%d", getpid());
			close(client);//关闭连接
			exit(-6);
		}
		else
		{
			close(client);//父进程关闭和客户端的连接,防止描述符耗尽
			printf("父进程开始执行\n");
		}
	}

	return 0;
}

