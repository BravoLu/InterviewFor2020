#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    int i = 0;
    printf("before fork\n");
    pid_t pid = fork();
    printf("after fork\n");
    if (pid<0){
        printf("error\n");
        return 1;
    }
    else if(pid==0){
        printf("fork success, this is son process\n");
        while(i<10){
            i += 1;
            printf("this is son process, i=%d\n", i);
            sleep(1);
        }
    }
    else{
        printf("fork success,this is father process, son process id is %d\n", pid);
        while(i<10){
            i += 2;
            printf("this is father process, i=%d\n", i);
            sleep(2);
        }
    }
    return 0;
}
