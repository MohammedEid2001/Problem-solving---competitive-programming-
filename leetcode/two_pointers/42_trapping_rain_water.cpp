/*
description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/


// basically, we look at the beginning and the end of the array and set current max for both sides, if the left side have smaller height, then we can safely move pointer i to the right, because we know the limiting factor is our left and we know the height of water will never exceed this level we are on roght now so we can add the differencr between our current and the left max, unlike right max which got the higher height and we have no idea if theres a taller or equal height pillar that will add more water level , so we basically skip moving it for now.
class Solution {
public:
    int trap(vector<int>& height) {
        int left_max= height [0], right_max =height.back();
        int i = 1; int j = height.size()-2;
        int som = 0;
        while(i <=j)
        {
            if(left_max< right_max)
            {
                som += max(0, left_max-height[i]);
                left_max= max(left_max,height[i]);
                ++i;
            }
            else
            {
                som += max(0, right_max-height[j]);
                right_max= max(right_max,height[j]);
               --j;
            }
        }
        return som;
        
    }
};