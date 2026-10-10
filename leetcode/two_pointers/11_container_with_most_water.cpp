/*
description:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
*/


// we make the pointers, and then for each two elements, move the pointee from the one with the least height, why? because we know it got the min height, so even if we move the bigger one, the area we get from new pair will always be less , because we are working with the same min even if its the bigger one, so basically we move the pointer from the smaller element in hopes of finding the bigger one.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; int j = height.size()-1; 
        pair<int,int>most{i,j};
        int highest=0;
        while(i<j)
        {
            int tmp  = min(height[i], height [j])*(j-i);
            if(tmp> highest)
            {
                most = {i,j};
                highest= tmp;
            }

            if( 
                height[i]>  height [j]
                )--j;
        else
        {
            ++i;
        }
        }
        return highest;
    }
};
