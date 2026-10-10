/*
problem statement:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

//the way to solve this is by using a linked list to make the queue and we be able to modify elements from the front and back easily in O(1), and to be able to access the elements in O(1) and move them to the start of the list we link the elements of the list with a hash map to point at the elements.
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if( cashe.find(key) == cashe.end())return -1;
        LRU.splice(LRU.begin(),LRU, cashe[key]);
        return cashe[key]->second;
    }
    
    void put(int key, int value) {
        if( cashe.find(key) != cashe.end())
        {
            cashe[key]->second = value;
            LRU.splice(LRU.begin(),LRU, cashe[key]);
        }
        else
        {
            if(LRU.size() == cap)
            {
            cashe.erase(LRU.back().first);
            LRU.pop_back();
            }
            LRU.push_front({key,value});
            cashe[key] = LRU.begin();
        }
        
    }
    int cap;
unordered_map<int,list<pair<int,int>>::iterator> cashe;
    list<pair<int,int>> LRU;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */