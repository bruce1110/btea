#include "apue.h"

int main()
{
	struct bs
	{
		unsigned a:1;
		unsigned b:3;
		unsigned c:4;
	} bit,*pbit;
	bit.a=1;
	bit.b=7;
	bit.c=15;
	printf("%d,%d,%d\n",bit.a,bit.b,bit.c);
	pbit=&bit;
	pbit->a=0;
	pbit->b&=3;//111&011 = 011 进行位与
	pbit->c|=1;//1111 | 0001 = 1111 进行为或
	printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
	struct test1
	{
		char a:1;//用一个字节去存储
		char :2;//空域，与前面的字节类型相同，两个域相加仍然小于八位，任然存储在一个字节中
		int b:2;//如果为b:30 程序运行结果为8
		char c:2;
	};
	int len = sizeof(struct test1);//整个结构体的总大小为最宽基本类型成员大小的整数倍,结果为4
	printf("test1 len:%d\n",len);
	return 0;
}
