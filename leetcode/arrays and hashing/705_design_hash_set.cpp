
/*
problem description:
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

//i simply made it by using a vector of boolean( true if the number is present and false if not) with length of the max possible number and then updated the array based on that
class MyHashSet {
public:
    MyHashSet() {
        hash_map = vector<bool>(1000001,0);
    }
    
    void add(int key) {
        hash_map[key]= true;
    }
    
    void remove(int key) {
        hash_map[key]=false;
    }
    
    bool contains(int key) {
        return hash_map[key];
    }
    vector<bool> hash_map;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */