#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int main(int argc,char * args[])
{
	struct timespec tp;
	struct tm t;
	char buf[64];
	//localtime不是线程安全的
	clock_gettime(CLOCK_REALTIME, &tp);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", localtime_r(&tp.tv_sec, &t));
	printf("%s", buf);
	return 0;
}
