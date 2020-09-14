#include<bits/stdc++.h>
using namespace std;
#define DOUBLE(x) x+x
#define I 5*DOUBLE(5)
//#define I 5
//
//
void change(int a[]){
    a[0] = 1001;
    cout<<a[0]<<endl;
}
using namespace std;
int main(){
    //cout<<I<<endl;
    //printf("%d", I);
    //char s[] = "hello";
    int s[] = {0,1,2,3};
    char *s2 = "hello"; 
    change(s);
    cout<<*s<<endl;
    cout<<s2[0]<<endl;
    //s2[0] = "K";
    return 0;
}
