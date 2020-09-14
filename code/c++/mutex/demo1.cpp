#include <iostream>
#include <thread> 
#include <vector>
#include <mutex> 
#include <chrono>
#include <stdexcept>

int counter = 0;
void increase(int time){
    for(int i = 0; i < time; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
    }
}

int main(int argc, char** argv){
    std::thread t1(increase, 10000);
    std::thread t2(increase, 10000);
    t1.join();
    t2.join();
    std::cout<<"counter:"<<counter<<std::endl;
    return 0;
}
