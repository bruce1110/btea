#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define LEN 128
int main()
{
	int fd;
	size_t buf[LEN];
	char * wbuf = "qinchong";
	ssize_t n;
	fd = open("/tmp/a.txt", O_APPEND);
	lseek(fd, 10, SEEK_SET);
	n = write(fd, wbuf, strlen(wbuf));//使用O_APPEND文件状态lseek后不可写
	if(n != strlen(wbuf))
		perror("write error");
	while( (n = read(fd, buf , LEN)) > 0 )//可读
	{
		printf("\nread buf len %d,: %s", n,buf);
	}
	close(fd);
	return 0;
}
