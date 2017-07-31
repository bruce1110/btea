#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

#define tnum 2
pthread_barrier_t b;
long int data[1024];
void * thr_fun(void * args)
{
	int i = (long)args;
	pthread_attr_t arr;
	printf("in thread%ld\n", (long)args);
	data[i] = i;
	size_t attr2_len;
	if(pthread_attr_getstacksize(&arr, &attr2_len) != 0)//进程获取进程栈大小
		perror("error");
	printf("thread statck size%d\n", attr2_len);
	sleep(5);
	pthread_barrier_wait(&b);
	return (void *)0;
}
int main()
{
	pthread_t tid;
	int err;
	unsigned long i;
	struct timeval end,start;
	pthread_attr_t arr;
	size_t attr_len;
	long long startusec,endusec;
	for(i=0;i< 1024;i++)
	{
		data[i] = random();
	}
	printf("start 1=%d,0=%d\n", data[1], data[0]);
	printf("min statck size%d\n", PTHREAD_STACK_MIN);//最小的线程栈大小
	gettimeofday(&start, NULL);
	pthread_barrier_init(&b, NULL, tnum+1);//屏障初始化，+1 是为了让当前的主线程处理数据
	if(pthread_attr_init(&arr) !=0 )
		perror("attr_init fail");
	attr_len = 102400;
	if(pthread_attr_setstacksize(&arr, attr_len) != 0)//设置进程栈大小
		perror("set fail");
	for(i = 0;i < tnum; i++)
	{
		err = pthread_create(&tid, &arr, thr_fun, (void * )i);
		if(err != 0)
			perror("create faild");
	}
	if(pthread_attr_getstacksize(&arr, &attr_len) != 0)//获取当前线程栈大小
		perror("attr_getstatcksize fail");
	printf("now stack_size:%d\n", attr_len);
	pthread_barrier_wait(&b);//所有的线程都调用该方法后会唤起所有线程继续执行

	gettimeofday(&end, NULL);
	printf("starttime:%lld\tendtime:%lld\n", start.tv_sec, end.tv_sec);
	printf("end 1=%ld,0=%d\n", data[1], data[0]);
	pthread_attr_destroy(&arr);
	return 0;
}
