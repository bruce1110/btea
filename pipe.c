#include "apue.h"


int main()
{
	int fd[2];
	pid_t p;
	char buf[MAXLINE];
	int n;

	if(pipe(fd) < 0)
		err_sys("pipe error");
	if( (p = fork()) < 0 )
		err_sys("fork error");
	else if(p > 0) //parent
	{
		close(fd[0]);//关闭读
		write(fd[1], "fucking\n", 8);
	}
	else
	{//child
		close(fd[1]);//关闭写
		n = read(fd[0], buf, MAXLINE);
		buf[n] = '\0';
		write(STDOUT_FILENO, buf, n+1);
	}
	exit(0);
}
