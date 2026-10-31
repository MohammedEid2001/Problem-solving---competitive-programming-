/*

description:
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() ==1)return 1;
        if(arr.size() == 2)  return (arr[0] ==arr[1]?1:2);
        int widest= 1 + (arr[0]!= arr[1]);
        int current = 1+(arr[0]!= arr[1]);
        bool bigger = arr[1] > arr[0];
        for(int i = 2; i < arr.size(); ++i)
        {
            //if oir 2 elements are equal, just skip and reset.
            if(arr[i]== arr[i-1]){current = 1;}
            else
            {
                //if last element was the start of new sub array
                if(current == 1 )
                {
                    ++current;
                    bigger = (arr[i]> arr[i-1]);
                }
                else
                    {
                        //if the signs between last two operations is different 
                        if(bigger^(arr[i]>arr[i-1]))
                        {
                            ++current;
                            bigger = !bigger;
                        }
                        else
                        {
                            current = 2;
                        }
                    }
            }
            widest = max(widest,current);
        }
        return widest;
    }
};
