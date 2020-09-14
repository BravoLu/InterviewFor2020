// heap sort 

#include <bits/stdc++.h>
using namespace std;

void adjust(vector<int>& arr,const int& len,const int &index){
   int maxid = index;
   int left=2*index+1, right=2*index+2;
   
   if(left<len && arr[left]<arr[maxid]) maxid=left;
   if(right<len && arr[right]<arr[maxid]) maxid=right;

   if(maxid!=index){
        swap(arr[index], arr[maxid]);
        adjust(arr, len, maxid);
   }
}

void heapsort(vector<int>& arr, const int &len){
    for(int i=(len-1-1)/2; i>=0; i--){
        adjust(arr, len, i);
    }
    for(int i=len-1;i>0;i--){
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }
}

int main(){
    vector<int> arr = {1, 7, 3, 2, 5, 6, 9};
    heapsort(arr, arr.size());
    for(auto i: arr){
        cout<<i<<" ";
    }
}
