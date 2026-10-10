/*
description:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/


//approach: make a hashmap to store the seen values, then if you find a duplicate you can return it does contain one

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,bool>uniq;
        bool uni = true;
        for(int i = 0; i< nums.size() && uni;++i)
        {
            if(uniq.find(nums[i])== uniq.end())uniq[nums[i]]=1;
            else
            {
                uni = false;
            }
        }
        return !uni;
    }

};