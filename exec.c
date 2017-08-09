#include "apue.h"
#include <sys/wait.h>
extern char ** environ;
/* exec函数： */
/* l：表示使用可变参数列表，并且最后一个参数为NULL */
/* p：表示path为文件名，自动在系统PATH中查找 */
/* e：可以传递环境变量，使用最后一个参数，类型为char * env[] */
/* v：表示命令所需的参数以char *arg[]形式给出且arg最后一个元素必须是NULL */
/* execl execlp execle execv execvp execve */
int main(int argc,char *args[])
{
	pid_t pid;
	/* printf("%s\n", getlogin()); */
	fflush(NULL);
	pid = fork();
	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)//child
	{
		err_msg("begin exec");
		printf("in child pid:%d\n", getpid());
		if(execle("./env", "env" ,"ok", NULL, environ) < 0)
			err_sys("exec error");
	}
	else
	{
		printf("int parent pid=%d\n", pid);
		if(waitpid(pid, NULL, 0) < 0)
			err_sys("wait error");
	}
	return 0;
}
