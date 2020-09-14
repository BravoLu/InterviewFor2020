#include <bits/stdc++.h>
#include <memory>
using namespace std; 

int main(){
    
    shared_ptr<int> p(new int(10));
    shared_ptr<int> p2 = make_shared<int> (10);
    
    /*
     * weak_ptr必须有一个shared_ptr作为构造函数
     * .lock() 返回weak_ptr的shared_ptr
     */
    
    weak_ptr<int> w_p(p);
    auto tmp = w_p.lock();
    cout<<*tmp<<endl;

    unique_ptr<int> u_p(new int(20));
    auto_ptr<int> c_p(new int(20));
}
