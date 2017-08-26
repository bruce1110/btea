#include "apue.h"
/**
 * @file coprocess.c
 * @brief 此进程中的子进程就是协同进程。其中协同进程的标准输入重定向到管道1，父进程向此管道写数据
 * 协同进程的标准输出重定向到管道2，父进程从此管道读数据。
 * @author Bruce
 * @version 
 * @date 2017-08-26
 */

static void sig_pipe(int);
int main()
{
    int n,fd1[2],fd2[2];
    pid_t pid;
    char buf[MAXLINE];
    if(signal(SIGPIPE, sig_pipe) == SIG_ERR)
        err_sys("signal error");
    if(pipe(fd1) < 0 || pipe(fd2) < 0)
        err_sys("pipe error");
    if((pid = fork()) < 0 )
    {
        err_sys("fork error");
    }
    else if(pid > 0 )//parent
    {
        close(fd1[0]);
        close(fd2[1]);

        while(fgets(buf , MAXLINE, stdin) != NULL)
        {
            n = strlen(buf);
            if(write(fd1[1], buf, n) != n)
                err_sys("write error to pipe");
            if(( n = read(fd2[0] , buf, MAXLINE)) < 0 )
                err_sys("read error from pipe");
            if( n == 0 )
            {
                err_msg("child close pipe");
                break;
            }
            buf[n] = 0;
            if(fputs(buf, stdout) == EOF)
                err_sys("fputs error");
        }
        if(ferror(stdin))
            err_sys("stdin error");
        exit(0);
    } else if(pid == 0){ //child
        close(fd1[1]);
        close(fd2[0]);
        if(dup2(fd1[0] , STDIN_FILENO) != STDIN_FILENO)
            err_sys("dup2 error");
        close(fd1[0]);
        if(dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO)
            err_sys("bup2 error");
        close(fd2[1]);

        int n1,n2;
        err_msg("child begin to reading");
        while( (n = read(STDIN_FILENO, buf, MAXLINE)) > 0)//如果使用标准io，此时从管道读数据是全缓冲的，子进程会一直阻塞读
        {
            buf[n] = 0;
            err_msg("recive data:%d", buf);
            if(sscanf(buf, "%d%d", &n1, &n2) == 2)
            {
                sprintf(buf, "%d\n", n1+n2);
                n = strlen(buf);
                if(write(STDOUT_FILENO, buf, n) != n)
                    err_sys("write error");
            } else {
                if(write(STDOUT_FILENO, "invalid args\n", 13) != 13)
                    err_sys("write error");
            }
        }
        exit(0);
    }
}

static void sig_pipe(int signo)
{
    err_msg("SIGPIPE caught");
    exit(1);
}
