/*

description:Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/

//implementation: to solve this problem, we just make a hashmap with unique string key (that we made to show :mhow many letters at each string is repeating to be able to group them)and then we simply group that result

class Solution {
public:

    string anagram_array(string &n)
    {
        string a(26,'1');
        for(int i = 0; i <n.size();++i)
        {
            ++a[n[i] -'a'];
        }
        return a;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string> > cashe;

        vector< vector<string> > sol;
        for(int i = 0; i <strs.size();++i)
        {
            string tmp = anagram_array(strs[i]);
            if(cashe.find(tmp) == cashe.end()) cashe[tmp]= {strs[i]};
            else{
                cashe[tmp].push_back(strs[i]);
            }
        }
        for(auto a: cashe)
            {
                sol.push_back(a.second);
            }
        return sol;
    }
};


//other approach(more optimized) 	: we make a custom hashkey to work on the array and  use it instead of the string

class Solution {
    struct KeyHash {
        size_t operator()(const std::array<int, 26>& k) const {
            size_t h = 0;
            for (int x : k)
                h = h * 1099511628211ULL ^ static_cast<size_t>(x);
            return h;
        }
    };

    std::array<int, 26> anagram_array(const std::string& n) {
        std::array<int, 26> a{};
        for (char c : n) ++a[c - 'a'];
        return a;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::array<int, 26>, vector<string>, KeyHash> cache;

        for (auto& s : strs)
            cache[anagram_array(s)].push_back(s);

        vector<vector<string>> sol;
        sol.reserve(cache.size());
        for (auto& kv : cache)
            sol.push_back(std::move(kv.second));
        return sol;
    }
};