/*
description:
*/

class Solution {
public:
    double calculate_time(vector<int>& p, int x) {
    double total = 0;
    for (double a : p) total += ceil(a/x);//(a + x - 1) / x;  
    return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    double Min = 1, Max = *max_element(piles.begin(), piles.end());
    double ans = Max;
    while (Min <= Max) {
        int mid = Min + (Max - Min) / 2;  
        double time = calculate_time(piles, mid);
        if (time <= h) {
            ans = mid;
            Max = mid - 1;    
        } else {
            Min = mid + 1;
        }
    }
    return ans;  
}
};


//changing the type of parameters from double to long and doing the "int ceil" approach helped speedup the code considerably