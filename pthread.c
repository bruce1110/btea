#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct foo {
	int a,b,c,d;
};
void printfoo(const char * s, const struct foo * fp)
{
	printf("%s", s);
	printf("struct foo at 0x%lx\n", (unsigned long) fp);
	printf("foo.a=%d,foo.b=%d,foo.c=%d,foo.d=%d\n", fp->a,fp->b,fp->c,fp->d);
}

void * thr_fun(void * arg)
{
	//线程在自己的栈上声明的变量，在thread_exit之后可能已经改变，可以使用malloc避免这种情况的发生
	/* struct foo f = {1,2,3,4}; */
	struct foo * fp = (struct foo *)malloc(sizeof(struct foo));
	fp->a = 1;
	fp->b = 2;
	fp->c = 3;
	fp->d = 4;
	printfoo("thread 1 :\n", fp);
	pthread_exit((void *)fp);
}
void * thr_fun2(void * arg)
{
	printf("thread 2 id is%lu", (unsigned long)pthread_self());
	pthread_exit((void *)0);
}

int main()
{
	int err;
	pthread_t ntid;
	struct foo * fp;
	err = pthread_create(&ntid, NULL, thr_fun, NULL);
	if(err != 0)
		return 1;
	err = pthread_join(ntid, (void *)&fp);
	if(err != 0)
		return 1;
	printfoo("parent :\n", fp);
	exit(0);
}
