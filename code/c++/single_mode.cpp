#include<iostream>
#include<mutex>
#include<pthread.h> 

//std::mutex mutex_lock;
// 懒汉模式，线程不安全

class SingleInstance{
    private:
        static SingleInstance *m_SingleInstance;
        SingleInstance(){
            std::cout<<"构造函数" << std::endl;
        }
        ~SingleInstance(){
            std::cout<<"析构函数" << std::endl;
        }
    public:
        // 获取单例对象
        static SingleInstance *GetInstance(){
            if(m_SingleInstance == NULL)
            {
                m_SingleInstance = new (std::nothrow) SingleInstance;
            }
            return m_SingleInstance;
        }
        // 释放单例，进程退出时调用
        static void deleteInstance(){
            if(m_SingleInstance)
            {
                delete m_SingleInstance;
                m_SingleInstance = NULL;
            }
        }
        void Print(){
            std::cout<<"我的实例内存地址是:" << this << std::endl;
        }
        // 打印单例模式
};

// C++ 饿汉模式
/*
class SingleInstancev2{
    private:
        static SingleInstancev2 *m_SingleInstance;
        SingleInstancev2(){
            std::cout<<"构造函数" << std::endl;
        }
        ~SingleInstancev2(){
            std::cout<<"析构函数" << std::endl;
        }
    public:
        static SingleInstancev2 *GetInstance(){
            if(m_SingleInstance == NULL){
                mutex_lock.lock();
                if(m_SingleInstance == NULL){
                    m_SingleInstance = new SingleInstancev2;
                }
                mutex_lock.unlock();
            }
        }

};
*/

// 线程函数
void *PrintHello(void *threadid)
{
    // 主线程与子线程分离，两者相互不干涉，子线程结束同时子线程的资源自动回收
    pthread_detach(pthread_self());

    // 对传入的参数进行强制类型转换，由无类型指针变为整形类型指针
    int tid = *((int *)threadid);

    std::cout << "Hi, 我是线程 ID:[" << tid << "]" << std::endl;

    SingleInstance::GetInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 5
int main(void)
{
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0};

    int ret = 0;
    int i = 0;

    std::cout << "main(): 开始 ... " << std::endl;
    for(i = 0; i < NUM_THREADS; i++)
    {
        std::cout << "main() : 创建线程: [" << i << "]" << std::endl;

        indexes[i] = i;

        ret = pthread_create(&threads[i], NULL, PrintHello, (void *)&(indexes[i]));
        if(ret)
        {
            std::cout << "Error:无法创建线程," << ret << std::endl;
            exit(-1);
        }
    }

    SingleInstance::deleteInstance();
    std::cout<<"main() :结束!" << std::endl;
    return 0;
}

