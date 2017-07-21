#ifndef __B_H_
#define __B_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>
#include <netdb.h>
/* *
 *
 *创建一个epoll的句柄
 * int epoll_create(int size); 
 *
 *注册要监听的事件类型
 *int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
 *
 *收集在epoll监控的事件中已经发送的事件,如果函数调用成功，返回对应I/O上已准备好的文件描述符数目，如返回0表示已超时。
 *int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
 *
 * 
 * op:
 * EPOLL_CTL_ADD：注册新的fd到epfd中；
 * EPOLL_CTL_MOD：修改已经注册的fd的监听事件
 * EPOLL_CTL_DEL：从epfd中删除一个fd
 *
 *struct epoll_event:
 * typedef union epoll_data {
 * void *ptr;  指向用户自定义数据 
 * int fd;  注册的文件描述符 
 * uint32_t u32;  32-bit integer 
 * uint64_t u64;  64-bit integer 
 * } epoll_data_t;
 *
 * struct epoll_event {
 * uint32_t events;  描述epoll事件 
 * epoll_data_t data;  见第一个结构体
 * };
 *events:
 *EPOLLIN ：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）； 
 *EPOLLOUT：表示对应的文件描述符可以写； 
 *EPOLLPRI：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）； 
 *EPOLLERR：表示对应的文件描述符发生错误； 
 *EPOLLHUP：表示对应的文件描述符被挂断； 
 *EPOLLET： 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。 
 *EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里


 *工作模式：Level Triggered水平触发
 *这个是缺省的工作模式。同时支持block socket和non-block socket。内核会告诉程序员一个文件描述符是否就绪了。如果程序员不作任何操作，内核仍会通知。
 *Edge Triggered 边缘触发
 *是一种高速模式。仅当状态发生变化的时候才获得通知。nginx 默认使用ET
 *
 */
typedef struct epoll_event * e_event;
int epoll_init();
int epoll_socket(int domain, int type, int protocol);
int epoll_cleanup();
int epoll_new_conn(int sfd);
#define MAX_SOCK_NUM 512
#define ADD EPOLL_CTL_ADD
#define MOB EPOLL_CTL_MOD
#define DEL EPOLL_CTL_DEL
#endif
