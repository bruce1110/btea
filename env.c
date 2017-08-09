#include "apue.h"
extern char ** environ;
int main(int argc,char * args[])
{
	printf("pid=%d\n", getpid());
	int i;
	for (i=0; environ[i]!=NULL; ++i)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
