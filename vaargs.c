#include "apue.h"
#include <stdarg.h>

int test(const char * fmt, ...);
int mon_loging(const char * fmt, ...);
int main(int argc, char * args[])
{
	int i = test("10010", "bruce", 123);
	return 0;
}

int test(const char * fmt, ...)
{
	va_list va;//这个参数指向参数列表
	va_start(va, fmt);//va指向可变参数列表的第一个参数的地址，msg为参数列表中第的一个固定参数
	char * msg1;
	int data,i;
	msg1 = va_arg(va, char *);//获取可变参数的当前参数，返回指定类型并将指针指向下一参数,第二个参数指定参数类型。
	data = va_arg(va, int);//继续获取
	/* char buf[MAXLINE]; */
	/* i = vsnprintf(buf, MAXLINE-1, fmt, va); */
	va_end(va);
	printf("%d\n", data);
	printf("%s\n", msg1);
	/* strcat(buf, "\n"); */
	/* fputs(buf, stderr); */
}
int mon_loging(const char* format, ...)
{
	char str_tmp[50];
	int i=0;
	va_list vArgList;                            //定义一个va_list型的变量,这个变量是指向参数的指针.
	va_start (vArgList, format);                 //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参数,是一个固定的参数
	i=vsnprintf(str_tmp, 50, format, vArgList); //注意,不要漏掉前面的_
	va_end(vArgList);                            //用va_end宏结束可变参数的获取
	return i;                                    //返回参数的字符个数中间有逗号间隔
}
