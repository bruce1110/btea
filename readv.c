#include "apue.h"
#include <sys/uio.h>
#include<fcntl.h>

int main()
{
	char buf1[5],buf2[10];
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0 ,sizeof(buf2));
	struct iovec iov[2];
	iov[0].iov_base = buf1;
	iov[0].iov_len = 5;
	iov[1].iov_base = buf2;
	iov[1].iov_len = 10;

	int fd = open("/tmp/a.txt", O_RDWR);
	if( fd < 0 )
		err_sys("open error");
	int rsize = readv(fd, iov, 2);
	if( rsize < 0 )
		err_sys("readv error");
	printf("read size:%d\n", rsize);
	close(fd);
	fd = open("/tmp/b.txt", O_RDWR|O_CREAT);
	if(fd < 0)
		err_sys("open error");
	int wsize = writev(fd, iov, 2);
	if(wsize < 0 )
		err_sys("writev error");
	printf("write size:%d\n", wsize);
	close(fd);
	return 0;
}
