#include <bits/stdc++.h>

using namespace std;

// increase
void QuickSort(vector<int>& arr, int left, int right){
    if(left>=right){
        return;
    }
    int cur = left-1;
    int rand_number = rand()%(right-left+1) + left;
    swap(arr[rand_number], arr[right]);
    for(int i=left; i<right; i++){
        if(arr[i]<=arr[right]){
            cur ++;
            swap(arr[i], arr[cur]);
        }
    }
    swap(arr[++cur], arr[right]);
    
    QuickSort(arr, left, cur-1);
    QuickSort(arr, cur+1, right);
    
    thread t1(QuickSort, ref(arr), left, cur-1);
    thread t2(QuickSort, ref(arr), cur+1, right);
    t1.join();
    t2.join();
    
}


int main(){
    vector<int> input = {0, 8, 7, 4, 10, 2, 1};
    for(auto value: input){
        cout<<value<<" "; 
    }
    cout<<endl;
    QuickSort(input, 0, input.size()-1);
    for(auto value: input){
        cout<<value<<" "; 
    }
    cout<<endl;
}
