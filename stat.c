#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	struct stat st, st2;
	int s;
	s = stat("/tmp/a.txt", &st);//lstat：当文件是符号链接时，返回符号链接的信息，stat返回时间文件的信息
	if(s == 0)
		printf("%d\n", st.st_mode);
	else
		perror("error");
	int fd = open("/tmp/a.txt", O_APPEND);
	s = fstat(fd, &st2);
	if(s == 0)
		printf("%d\n", st2.st_mode);
	else
		perror("fstat error");
	if(S_ISREG(st2.st_mode))
		printf("是普通文件\n");
	else
		printf("不是普通文件\n");
	if(access("/tmp/a.txt", F_OK) < 0)
		perror("error access");
	else
		printf("ok");
}
