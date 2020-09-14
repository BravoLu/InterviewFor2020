#include <iostream>
#include <thread>
//#include <stdlib.h>
#include <unistd.h>

using namespace std;

void t1()
{
    for(int i=0; i<10; i++){
        cout << "t1" << endl;
        sleep(1);
    }
}

void t2()
{
    for(int i=0; i<20; i++){
        cout << "t2" << endl;
    }
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
