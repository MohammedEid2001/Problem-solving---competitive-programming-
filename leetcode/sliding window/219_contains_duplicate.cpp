/*
description	:
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/

//sorting and sweeping solution O(n log(n) complexity)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector< pair<int,int> > num;
        for(int i = 0; i<nums.size();++i)num.push_back( {nums[i],i});
        sort(num.begin(),num.end());
        for(int i = 0; i <nums.size()-1;++i)
        {
            for(int j = i+1; j <nums.size()&& num[i].first==num[j].first;++j)
        if( abs(num[j].second-num[i].second) <= k)return 
        true;
        }
        return false;
    }
};



//the sliding window solution hashmap(theoretically O(n) faster but practically slower and takes more memory)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;

        unordered_set<int> window;
        window.reserve(min((size_t)k + 1, nums.size() * 2 + 1));

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!window.insert(nums[i]).second)   // already present → duplicate within k
                return true;

            if ((int)window.size() > k)           // keep only last k elements
                window.erase(nums[i - k]);
        }
        return false;
    }
};


//sorting + pointer solution ( memory beats 100%):
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        if (n < 2 || k <= 0) return false;

        // vector<int*> pointing into nums , sort keys are the pointers themselves
        std::vector<int*> loc(n);
        int* const base = nums.data();
        for (int i = 0; i < n; ++i) loc[i] = base + i;

        // sort by value, tie-break by address (= by original index, since
        // all pointers point into the same contiguous nums array)
        std::sort(loc.begin(), loc.end(), [](int* a, int* b) {
            return *a < *b || (*a == *b && a < b);
        });

        // within each equal-value group, indices are ascending (tie-break above),
        // so consecutive entries already give the minimum index distance.
        // loc[i+1] - loc[i]  ==  index(loc[i+1]) - index(loc[i])   ← no distance() needed
        for (int i = 0; i + 1 < n; ++i) {
            if (*loc[i] == *loc[i+1] && (loc[i+1] - loc[i]) <= k)
                return true;
        }
        return false;
    }
};
