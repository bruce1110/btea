#include "apue.h"
#include <sys/fcntl.h>
#include <unistd.h>
void sig_hand(int);
void sig_hand2(int);
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
			printf("i=%d\n", i);
		}
		printf("%d\n", i);
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
		char buf[] = "sigusr2\n";
		write(STDOUT_FILENO, buf, strlen(buf));
	}
}
