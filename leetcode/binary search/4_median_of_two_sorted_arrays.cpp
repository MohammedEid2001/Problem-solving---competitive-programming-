/*
description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/


//approach: we know that the median is at med=(n+m)/2  roughly (without considering odd/even count) , so basically, we grab the array with less lemgth and do binary search on it,taking exactly (n+m)/2 where lemgth of the median pooint we took for first element and the point for second equals.
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;   

        int low = 0, high = m;            

        while (low <= high) {
            int i = (low + high) / 2;     
            int j = totalLeft - i;        

            int left1  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i]     : INT_MAX;
            int left2  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j]     : INT_MAX;

            if (left1 > right2) {
                high = i - 1;
            }
            else if (left2 > right1) {
                low = i + 1;
            }
            else {
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);               
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        }
        return 0;
    }
};