/*
description:
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

//to make the summing faster, we just pre sum all the values from left to right and later substitute the range we need only.
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        numbers = nums;
        for(int i= 1; i < nums.size();++i)
        numbers[i] += numbers[i-1];
    }
    
    int sumRange(int left, int right) {
        return numbers[right]- ( left == 0?0:numbers[left-1]);
    }
    vector<int> numbers;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */