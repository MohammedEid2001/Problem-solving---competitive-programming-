/*
description:
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
*/

//my implementation uses hashmaps with vector inside to point the specific timestamp for each key vLue pair 

class TimeMap {
public:
    unordered_map< string ,vector<pair<int,string> >> Map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       /* if(Map.find(key) != Map.end())
        {
            
        }*/
        Map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(Map.find(key) == Map.end() ) return "";
        vector< pair<int,string>> &v = Map[key];
        auto it = std::upper_bound(
    v.begin(), v.end(), timestamp,
    [](int ts, const pair<int,string>& p){ return ts < p.first; }
);
    if (it != v.begin()) {
        --it; 
        return it->second;
        //std::cout << "Element <= " << target << " is: " << *it << '\n';
    } else {
        return "";
    }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
