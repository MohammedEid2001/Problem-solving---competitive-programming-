//the problem is to find the two number's indexes that if summed up will give us the target we want 	(in less than n^2 complexity
/*
statement:
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
  {
        unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); ++i) 
    {
    int complement = target - nums[i];
    auto it = seen.find(complement);
    if (it != seen.end())
        return {it->second, i};
    seen[nums[i]] = i;
    }
      return {};
  }
};