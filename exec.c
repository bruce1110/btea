#include "apue.h"
#include <sys/wait.h>
extern char ** environ;
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
