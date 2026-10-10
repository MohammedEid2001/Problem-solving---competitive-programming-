//you are asked to find if an array have duplicates or not and return what you found as T/F

/*
statement:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/class Solution 
{
 public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> uniq( nums.begin(), nums.end());
        return !(uniq.size()== nums.size());
    }
};
