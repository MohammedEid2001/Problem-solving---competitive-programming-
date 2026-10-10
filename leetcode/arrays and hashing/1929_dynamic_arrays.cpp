//leetcode problem "concatenation of array", you have an array and you want to duplicate the answers and append two copies of the same array together

/*
problem statement:Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.:
*/
class Solution {
public:
    vector<int> getConcatenation(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};