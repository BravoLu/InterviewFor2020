#include <bits/stdc++.h>
using namespace std;

// unordered_map<int, list<pair<int, int> > > cache; 
// list<pair<int, int> > auxlist;

class LRUCache{
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int> >::iterator > cache;
public:
    LRUCache(int capacity){
        cap = capacity;
    }
    int get(int key){
        auto mapitera = cache.find(key);
        if(mapitera==cache.end()){
            return -1;
        }else{
            list<pair<int, int>>::iterator listItera = mapitera->second;
            int value = (*listItera).second; 

            l.erase(listItera);
            l.push_front({key, value});
            cache[key]=l.begin();

            return value;
        }
    }
    void put(int key, int value){
        auto itera = cache.find(key);
        if(itera!=cache.end()){
            list<pair<int, int>>::iterator listItera = itera->second;

            l.erase(listItera);
            l.push_front({key, value});
            cache[key]=l.begin();

        }else{
            if(cache.size()>=cap){
                pair<int, int> oldpair = l.back();
                l.pop_back();
                cache.erase(oldpair.first);
            }
            l.push_front({key, value});
            cache[key] = l.begin();
        }
    }
};

int main(){
    int capacity = 5;
    int key = 0;
    int value = 1;
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);
    return 0;
}

