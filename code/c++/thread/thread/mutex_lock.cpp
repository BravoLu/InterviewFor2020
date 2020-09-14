#include <iostream>
#include <thread>
//#include <stdlib.h>
#include <unistd.h>
#include <mutex>
using namespace std;

mutex global_lock;

void t1()
{
    global_lock.lock();
    for(int i=0; i<10; i++){
        cout << "t1" << endl;
        sleep(1);
    }
    global_lock.unlock();
}

void t2()
{
    global_lock.lock();
    for(int i=0; i<20; i++){
        cout << "t2" << endl;
    }
    global_lock.unlock();
}

int main()
{
    thread th1(t1);
    //th1.join();
    thread th2(t2);

    th1.join();
    th2.join();

    cout << "main function" << endl;
    return 0;
}
