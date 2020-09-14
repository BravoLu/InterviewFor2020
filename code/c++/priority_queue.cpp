#include<bits/stdc++.h> 
using namespace std;
/*
 * priority_queue<Type, Container, Functional>
 */
int main(){
    // 大顶堆
    priority_queue<int>  heap;
    heap.push(1);
    heap.push(2);
    heap.push(-1);
    heap.push(0);
    //printf("%d", heap.top());
    //for(auto& item: heap){
    //    cout<<item<<" ";
    //}
    
    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
    
    // 小顶堆
    priority_queue<int, vector<int>, greater<int> > min_heap;
    min_heap.push(0);
    min_heap.push(1);
    min_heap.push(-1);
   
    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
    
}
