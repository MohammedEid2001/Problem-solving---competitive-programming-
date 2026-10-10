/*
description:
You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.

Find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        pair<int,int> sol;
        for(int i = 0; i < numbers.size(); ++i)
        {
            int second = target- numbers[i];
             auto it = lower_bound(numbers.begin()+i+1,numbers.end(), second);
            if( it != numbers.end() && *it == second)
            return vector<int>{
                i+1 ,  static_cast<int>(it-numbers.begin())+1
                   };
        }
        return {};
    }
};


//faster O(n) two pointers solution :
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = (int)numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return { i + 1, j + 1 };
            if (sum < target) ++i;
            else              --j;
        }
        return {};
    }
};
