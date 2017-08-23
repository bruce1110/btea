#include "apue.h"
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int fd;
	fd = open("/tmp/a.txt", O_RDWR);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	if(fcntl(fd, F_SETLK, &lock) < 0)
		err_sys("fcntl error");
	pid_t pid;
	pid = fork();//fork后会清除文件描述符上面的记录锁
	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)//child
	{
		err_msg("in child");
		char * buf;
		int n;
		if(fcntl(fd, F_SETLK, &lock) < 0)
		{
			err_sys("child fcntl error");
		}
		if((n = read(fd , buf ,10)) == -1)
			err_sys("read error");
		*(buf + n) = '\0';
		printf("%s", buf);
	}
	else
	{
		wait(pid);
	}
	return 0;
}
