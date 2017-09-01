#include "apue.h"
#include <stdarg.h>

int test(const char * msg, ...);
int main(int argc, char * args[])
{
	test("10010", "bruce", 1000);
	return 0;
}

int test(const char * msg, ...)
{
	va_list va;//这个参数指向参数列表
	va_start(va, msg);//va指向可变参数列表的第一个参数的地址，msg为参数列表中第的一个固定参数
	char * msg1;
	int data;
	msg1 = va_arg(va, char *);//获取可变参数的当前参数，返回指定类型并将指针指向下一参数,第二个参数指定参数类型。
	data = va_arg(va, int);//继续获取
	va_end(va);
	printf("%s\n", msg1);
	printf("%d\n", data);
}
