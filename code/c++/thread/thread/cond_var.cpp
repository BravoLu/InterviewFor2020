#include <iostream>
#include <string> 
#include <thread> 
#include <mutex>
#include <condition_variable>
#include <unistd.h>

std::mutex mutex;
std::condition_variable cv;
std::string data;

bool ready = false;
bool processed = false;

// 工作线程
void Worker(){
    std::unique_lock<std::mutex> lock(mutex);

    //等待主线程发送数据
    cv.wait(lock, []{return ready;});

    //等待后，继续拥有锁
    // 3 
    std::cout << "工作线程正在处理数据..." << std::endl;
    // 睡眠一秒以模拟数据处理
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    sleep(1);
    data += " 已处理";

    processed = true;
    // 4
    std::cout << "工作线程通知数据已经处理完毕。" << std::endl;

    lock.unlock();

    cv.notify_one();
}

int main(){
    std::thread worker(Worker);

    //数据发送给工作线程
    {
        std::lock_guard<std::mutex> lock(mutex);
        // 1 
        std::cout << "主线程正在准备数据..." << std::endl;
        // 睡眠1s以模拟数据准备
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        sleep(1);
        data = "样本数据";
        ready = true;
        // 2 
        std::cout << "主线程通知数据已经准备完毕。" << std::endl;
    }
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, []{return processed; }); 
    }
    // 5  
    std::cout << "回到主线程，数据 =" << data << std::endl;

    worker.join();
    return 0;
}

