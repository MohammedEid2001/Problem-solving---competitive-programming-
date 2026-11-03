/*
description:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        
        while(left< right)
        {
            if(nums[left]<nums[right])return nums[left];
            //if(left == right)return nums[left];
            int mid = (left +right)/2;
            if(nums[mid]>=nums[left]){left = mid+1;}
            else
            {
                right = mid;
               // if(right-left == 1)return min(nums[left],nums[right]);
            }
        }
        return nums[right];
    }
};


//a more redable code:

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;        // min is in right half
            } else {
                right = mid;           // min is at mid or left half
            }
        }
        return nums[left];
    }
};