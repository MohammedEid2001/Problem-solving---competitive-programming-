/*
description:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int combinations= 0;
        for(int i = i ; i<nums.size() ; ++i)
        {
           // bool possible= true;
           // vector<int> can;
            //can.push_back(nums[i]);
            int sum = 0;
           // long j = i+1;
           // while(!possible &&  sum != k && j< nums.size())
            for(long j = i; j < nums.size() ; ++j)
            { //can.push_back(nums[j]);
                sum += nums[j];
                //++j;
                if(sum == k) ++combinations;
                //possible = true;
            }
             //if(possible || sum == k)++combinations;
        }

        return combinations;
    }
    
};
