/*
description:
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

//we go backwards on the vector, if the next day got warmer tempreature, we see if the tempreature of the day thats got warmer tempreayure than that day can be warmer(if there), if not we just keep it -1

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector< int > pointing(temperatures.size() , -1);      
        for(int i = temperatures.size()-2; i >=0 ; --i)
        {
            int indx = i+1;
            while( indx != -1 && temperatures[indx] <= temperatures[i] )
            {
                indx = pointing[indx];
            }
                pointing[i]= indx;
           
        }
        for(int i = 0; i < pointing.size() ; ++i)
            pointing[i]=(pointing[i] == -1 ? 0 : pointing[i] - i);

        return pointing;
    }
};


//ankther version of the code that shouldve been faster, but leetcode says the first version is faster, it basically runs on a stack, we go from first element, add elements to the stack, and then for each element we add, we see if its warmer than the top of our stack, if yes, we pop that element of the stack and add the distacne between this temp and the one that was in top, and continue until we can pol from the stack, then add the tempreature we are on right now to the stack again , and so on:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        vector<int> st(n);   // pre-allocated stack
        int top = -1;

        for (int i = 0; i < n; ++i) {
            while (top >= 0 && temperatures[i] > temperatures[st[top]]) {
                int idx = st[top--];
                res[idx] = i - idx;
            }
            st[++top] = i;
        }
        return res;
    }
};