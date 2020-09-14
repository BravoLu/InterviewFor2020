#include <bits/stdc++.h>
typedef std::map<int, std::string> ID2NAME;

int main(){
    ID2NAME id2name;
    id2name.insert(std::pair<int, std::string>(2, "shaohao"));
    //id2name.insert({2, "shaohao"}); 
    printf("%s\n", id2name[2].c_str());    
    //int a[] = {1,4,3,2};
    //
    int a[] = {1,2,3,4};
    int *r = std::lower_bound(a, a+4, 3); 
    printf("%d", *r);
    
    return 0;

}
