
/*
description:
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/

// we build the prefix sum array in O(n) time, then we can get the pivot at O(n) time.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        sums.resize(nums.size(),0);
        sums=nums;
        for(int i = 1; i <nums.size();++i)
        {
            sums[i] += sums[i-1];
        }
        int index = -1;
        for(int i = 0;i<sums.size(); ++i)
        {
            if(sums[i]-nums[i] == sums[sums.size()-1]-sums[i]  ){index = i; break;}
        }
        return index;
    }

    vector<int> sums;
};
