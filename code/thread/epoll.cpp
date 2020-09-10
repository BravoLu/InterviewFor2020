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
    	����һ��epoll event,
    	
		int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
		���ڿ���ĳ��epoll event�ϵ��¼�������ע���¼����޸��¼���ɾ���¼� 
		������
			epfd: ��epoll_create���ɵ�epollר���ļ�������
		 	op: EPOLL_CTL_ADD ע�� EPOLL_CTL_MOD �޸� EPOLL_CTL_DEL ɾ��
			fd: �������ļ�������
			event: ָ��epoll_event��ָ�� 
	 	
	 	int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
	 	�ú���������Ҫ������¼���Ŀ������0��ʾ�ѳ�ʱ�����ص��¼�������events�����У�����ʵ�ʴ�ŵĳ�Ա�����ķ���ֵ������0��ʾ�Ѿ���ʱ�� 
		 ������
		 	epfd: epoll event
			events: �������ں˵õ��¼��ļ��� 
			maxevents: ÿ���ܴ�����¼���
			timeout: �ȴ�I/O�¼������ĳ�ʱֵ 
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
