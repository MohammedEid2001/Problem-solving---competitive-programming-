/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

*/

//n logn solution of sorting then solving


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            int start = 0; int end =0;int longest = 1;
            for(int i = 1; i<nums.size();++i)
            {
                end = i;
                int length = nums[end]- nums[start]+1;
                if(nums[i]== nums[i-1]+1 || nums[i] == nums[i-1]
                     ) 
                {
                    if(length > longest)longest = length;
                }
                else
                {
                    start = i ; end = i;
                }
            }
            return (nums.size()?longest : 0);
    }
};


// n solution of hashmap, every element is visited at most 2 times using the hashmap.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int n : s) {
            if (s.count(n - 1)) continue;   // not a sequence start
            int length = 1;
            while (s.count(n + length)) ++length;
            longest = max(longest, length);
        }
        return longest;
    }
};
