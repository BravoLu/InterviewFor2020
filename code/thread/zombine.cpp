#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
   产生一个僵尸进程，父进程没有调用wait。
fork:
    1) 父进程中，fork返回新创建子进程的进程ID。
    2) 在子进程，fork返回0
    3) 如果出现错误，fork返回0
wait:父进程等待子进程结束，并销毁子进程，如果父进程不调用wait函数，子进程就会一直留在Linux内核，变成僵尸进程。
*/
int main(){
    /* 创建一个一样的进程 */
    pid_t pid = fork();
    if(pid>0){/* 父进程 */
        printf("in parent process, sleep for one minute...zZ...\n");
        sleep(3);
        printf("after sleeping, and exit!\n");
    }else if(pid==0){
        /* 子进程退出，成为一个僵尸进程 */
        printf("in child process, and exit!\n");
        exit(0);
    }
    return 0;
}
