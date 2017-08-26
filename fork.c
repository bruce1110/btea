#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
char buf[] = "this is a buffer\n";
int global = 6;
int main()
{
	int var;
	pid_t pid;
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		exit(1);
	printf("pid:%ldbefore fork\n", (long)getpid());//没有flush，子进程缓冲区也会有内容
	if((pid = fork()) < 0 )
		exit(2);
	else if(pid == 0)
	{
		global ++;
		var ++;
	}else
	{
		sleep(2);
	}

	printf("pid = %ld,global = %d,var= %d\n", (long)getpid(), global, var);
	exit(0);
}
