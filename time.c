#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int main(int argc,char * args[])
{
	struct timespec tp;
	time_t t;
	struct tm *tm;
	char buf[64];
	clock_gettime(CLOCK_REALTIME, &tp);
	t = tp.tv_sec;
	tm = localtime(&t);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", tm);
	printf("%s", buf);
	return 0;
}
