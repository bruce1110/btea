#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/**
 * @brief 显示可分为编译时限制和运行时限制
 *
 * @params argc
 * @params args[]
 *
 * @return
 */
int main(int argc,char * args[])
{
	printf("%d\n", sysconf(_SC_PAGESIZE));
	printf("%d\n", sysconf(_SC_OPEN_MAX));
	return 0;
}
