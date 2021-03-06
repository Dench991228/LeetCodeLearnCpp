#include <queue>
#include <map>

using namespace std;

class CacheItem{
private:
    int last_update;
    int key;
    int value;
public:
    CacheItem(int k, int v):key(k), value(v){}
    void SetUpdateTime(int t){
        this -> last_update = t;
    }
    void Modify(int v, int t){
        this -> last_update = t;
        this -> value = v;
    }
    int GetValue(){
        return this -> value;
    }
    int GetKey(){
        return this -> key;
    }
    int GetTime(){
        return this -> last_update;
    }
    bool operator > (CacheItem ci){
        return this -> last_update > ci.last_update;
    }
};

class LRUCache {
private:
    long current_time;
    int max_capacity;
    map<int, CacheItem*> time_items;
    map<int, CacheItem*> key_items;
public:
    LRUCache(int capacity) {
        time_items = map<int, CacheItem*>();
        key_items = map<int, CacheItem*>();
        current_time = 0;
        max_capacity = capacity;
    }
    
    int get(int key) {
        map<int, CacheItem*>::iterator it = key_items.find(key);
        if(it == key_items.end())return -1;
        CacheItem *c = (*it).second;
        time_items.erase(time_items.find(c->GetTime()));
        c->SetUpdateTime(current_time);
        time_items.insert(pair<int, CacheItem*>(c->GetTime(), c));
        current_time ++;
        return c->GetValue();
    }
    
    void put(int key, int value) {
        if(key_items.find(key)!=key_items.end()){//更新数据
            CacheItem *c = (*key_items.find(key)).second;
            time_items.erase(time_items.find(c->GetTime()));
            c->Modify(value, current_time);
            time_items.insert(pair<int, CacheItem*>(c->GetTime(), c));
        } else{ 
            if(key_items.size() == this -> max_capacity){//删除数据
                CacheItem *c = (*time_items.begin()).second;
                time_items.erase(time_items.begin());
                key_items.erase(key_items.find(c->GetKey()));
            }
            CacheItem *c = new CacheItem(key, value);
            c->SetUpdateTime(current_time);
            key_items.insert(pair<int, CacheItem*>(key, c));
            time_items.insert(pair<int, CacheItem*>(current_time, c));
        }
        current_time++;
    }
};