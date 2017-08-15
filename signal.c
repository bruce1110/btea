#include "apue.h"
#include <sys/fcntl.h>
#include <unistd.h>
void sig_hand(int);
void sig_hand2(int);

/**
 * @file signal.c
 * @brief 本例可以看出如果不用换行符刷新缓冲区，输出会混乱
 * 标准的io函数都是不可重入的
 * @author Bruce
 * @version 
 * @date 2017-08-15
 */

int main()
{
	if(signal(SIGUSR1, sig_hand) == SIG_ERR)
		err_sys("signal_err");
	if(signal(SIGUSR2, sig_hand2) == SIG_ERR)
		err_sys("signal_err");
	for(;;)
		pause();
	return 0;
}
void sig_hand(int signo)
{
	if(signo == SIGUSR1)
	{
		int i=0;
		while(1)
		{
			i++;
			if(i == 20)
				break;
			sleep(1);
			printf(",i=%d", i);
		}
		printf("end:%d\n", i);
		char buf[] = "sigusr1\n";
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	else if(signo == SIGUSR2)
	{
		char buf[] = "sigusr2\n";
		write(STDOUT_FILENO, buf, strlen(buf));
	}
}

void sig_hand2(int signo)
{
	if(signo == SIGUSR2)
	{
		int i=0;
		while(1)
		{
			i++;
			if(i == 20)
				break;
			sleep(1);
			printf("%d->", i);
		}
		printf("end2:%d\n", i);
		char buf[] = "sigusr2\n";
		write(STDOUT_FILENO, buf, strlen(buf));
	}
}
