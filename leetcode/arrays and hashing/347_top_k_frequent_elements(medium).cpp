/*
description:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in
*/

//implementation: make a hashmap to count the occurences of each number in O(n), then make a bucket to save the elements based on thier frequencies in O(n), and then add that to the final array in O(k).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cashe;
        int Max = 0;
        cashe.reserve(nums.size());
        for(int &a : nums){
            ++cashe[a];
            if(cashe[a] > Max)Max = cashe[a];
        }
        vector< vector<int>> topk(Max+1);
        //topk.reserve(cashe.size());
        for(auto a : cashe)
            {
                topk[a.second].push_back(a.first);
            }
        vector<int> final;
        final.reserve(k);
        bool done = false;
        for(int i = topk.size()-1; i>=0 && !done; --i)
            {
                for(int j = 0; j< topk[i].size() && !done ;++j)
                    {
                        final.push_back(topk[i][j]);
                        if(final.size() == k)done = true;
                    }
            }

        return final;
        
    }
    
};


/*

more vectorized version, where instead of making a vector of vector, we just make a count array to count how many of each freuqnecy we have , then after that we make another array pos just to reserve positions for these elements and store them there, in a way that it shows at which index will thw given frequency be starting from, and then at the sorted array we just add them in that order.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq.reserve(nums.size());
        int maxFreq = 0;
        for (int num : nums) {
            int c = ++freq[num];
            if (c > maxFreq) maxFreq = c;
        }

        // count how many numbers have each frequency
        vector<int> count(maxFreq + 1, 0);
        for (const auto& p : freq) ++count[p.second];

        // starting index in the sorted array for each frequency (descending)
        vector<int> pos(maxFreq + 1);
        int idx = 0;
        for (int f = maxFreq; f >= 1; --f) {
            pos[f] = idx;
            idx += count[f];
        }

        // place numbers into the flat sorted array
        vector<int> sorted(freq.size());
        for (const auto& p : freq) {
            sorted[pos[p.second]++] = p.first;
        }

        return {sorted.begin(), sorted.begin() + k};
    }
};