/*
dewcription:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space

*/class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    vector<bool>found(nums.size()+1,0);
    for (int x : nums) {
        if(found[x]){return x;}
        found[x]= true;
    }
    return -1;                       // unreachable
    }
    /*int findDuplicate(vector<int>& nums) {
        
    }*/
};

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];          // slow: 1 house
        fast = nums[nums[fast]];    // fast: 2 houses
    } while (slow != fast);         // STOP: met inside the loop

    slow = nums[0];                 // send slow back to start
    while (slow != fast) {
        slow = nums[slow];          // both: 1 house
        fast = nums[fast];
    }
    return slow;                    // they met at the entrance = duplicate
}
