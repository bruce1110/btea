#include "apue.h"
#include <sys/uio.h>
#include<fcntl.h>

int main()
{
	char buf1[10],buf2[10];
	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0 ,sizeof(buf2));
	struct iovec iov[2];
	int fd = open("/tmp/a.txt", O_RDWR);
	if( fd < 0 )
		err_sys("open error");
	int rsize = read(fd, buf1, 10);
	if( rsize < 0 )
		err_sys("readv error");
	printf("read size:%d\n", rsize);
	buf1[rsize] = '\0';
	printf("buf1:%s", buf1);
	close(fd);
	fd = open("/tmp/c.txt", O_RDWR);
	if( fd < 0 )
		err_sys("open error");
	int rsize2 = read(fd, buf2, 10);
	if( rsize < 0 )
		err_sys("readv error");
	printf("read size:%d\n", rsize2);
	close(fd);
	iov[0].iov_base = buf1;//每个缓冲区的长度可以按照读入的长度确定
	iov[0].iov_len = rsize;
	iov[1].iov_base = buf2;//多册读入，离散读
	iov[1].iov_len = rsize2;
	fd = open("/tmp/b.txt", O_RDWR|O_CREAT, 0644);
	if(fd < 0)
		err_sys("open error");
	int wsize = writev(fd, iov, 2);//一次性写入，聚集写
	if(wsize < 0 )
		err_sys("writev error");
	printf("write size:%d\n", wsize);
	close(fd);
	return 0;
}
