/*
description:

*/

//we make a sliding window that have the sum of the current k elements, and when we move by 1, we always substarct element behind and add the new element on front, and test on that 

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k)return 0;
        int Subs =0;
        double Sum =0.0;
        for(int i = 0;i <k ; ++i)Sum += arr[i];
        if(Sum/k >= threshold)++Subs;
        for(int i = 1 ; i <=arr.size()-k ;++i)
        {
            Sum +=(arr[i+k-1]-arr[i-1]);
            if(Sum/k >= threshold )++Subs;
        }
        return Subs;
    }
};
