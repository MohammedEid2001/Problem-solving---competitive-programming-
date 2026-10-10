/*
description:
*/


//the solution im using works with a stack and visits all elements twice, once to find a smaller element right to all elements we found, and one from right to left to find the elements to the left of our element smaller than it, where we make the stack, then at each element of the array, we see if its shorter than the top of the stak, if no, we add it to the stak as well to find a smaller one after it, if yes, what we do is set its right at that element, we pop it off the stack, and we continue to see if the element bellow it was shorter than current element as well to see if we want to pop it and set i as its right element as well or not, doing that for all elements.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector< pair<int,int> > boundaries(heights.size(), {-1, heights.size()});
        vector<int> stak;
        stak.reserve(boundaries.size());
        //right sweep
        for(int i = 0 ; i <boundaries.size(); ++i)
        {
            if(stak.size()> 0)
            {
                while(stak.size() > 0 && heights[stak.back()] >  heights[i])
                {
                boundaries[stak.back()].second= i;
                    stak.pop_back();
                }
            }
            stak.push_back(i);
        }
        //left sweep
        while(stak.size())stak.pop_back();
        for(int i = boundaries.size()-1; i >= 0; --i)
        {
            if(stak.size()>0)
            {
                while(stak.size() > 0 && heights[stak.back()] >  heights[i])
                {
                boundaries[stak.back()].first= i;
                    stak.pop_back();
                }
            }
            stak.push_back(i);
        }
        int mx = 0;
        for(int i = 0; i < boundaries.size(); ++i)
        {
            int area =(boundaries[i].second-boundaries[i].first-1)*heights[i];
            if(area > mx)mx = area ;
        }
        return mx;
    }
};


//most optimised solution: we do only one sweep, where the goal is to find only the right element with shorter bar, because we know the left shorer bar will be the next element in the stak(below the one we want to find its right) because logically, the reason it wasnt popped was because we didnt find its right! so every element that came after it was biggee than it, thus the one just in top of the stak that we are trying to find its right is the first one bigger than it.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> stak;
        stak.reserve(n + 1);

        int mx = 0;

        for (int i = 0; i <= n; ++i) {
            // Sentinel: treat i == n as a bar of height 0
            int curHeight = (i == n) ? 0 : heights[i];

            while (!stak.empty() && heights[stak.back()] > curHeight) {
                int h = heights[stak.back()];
                stak.pop_back();

                int leftBoundary  = stak.empty() ? -1 : stak.back();
                int width = i - leftBoundary - 1;
                int area  = h * width;
                if (area > mx) mx = area;
            }

            stak.push_back(i);
        }

        return mx;
    }
};