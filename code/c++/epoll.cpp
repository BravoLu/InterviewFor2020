#include<unistd.h>
#include<iostream>
#include<sys/epoll.h>
using namespace std;

int main(void)
{
    int epfd, nfds;
    struct epoll_event ev, events[5];
    /*
    	int epoll_create(int size);
    	创建一个epoll event,
    	
		int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
		用于控制某个epoll event上的事件，可以注册事件，修改事件，删除事件 
		参数：
			epfd: 由epoll_create生成的epoll专用文件描述符
		 	op: EPOLL_CTL_ADD 注册 EPOLL_CTL_MOD 修改 EPOLL_CTL_DEL 删除
			fd: 关联的文件描述符
			event: 指向epoll_event的指针 
	 	
	 	int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
	 	该函数返回需要处理的事件数目，返回0表示已超时，返回的事件集合在events数组中，数组实际存放的成员个数的返回值，返回0表示已经超时。 
		 参数：
		 	epfd: epoll event
			events: 用来从内核得到事件的集合 
			maxevents: 每次能处理的事件数
			timeout: 等待I/O事件发生的超时值 
	 */
    epfd=epoll_create(1);
    ev.data.fd=STDIN_FILENO;
    //ev.events=EPOLLIN|EPOLLET;
    ev.events=EPOLLIN;
    //
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);
    for(;;)
    {
        nfds=epoll_wait(epfd, events, 5, -1);
        for(int i=0;i<nfds;i++)
        {
            if(events[i].data.fd==STDIN_FILENO)
                cout<<"hello world"<<endl;
        }
    }
}
