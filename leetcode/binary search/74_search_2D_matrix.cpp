/*
description:
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ColS =0, ColE =matrix[0].size()-1;
        int RowS = 0, RowE = matrix.size()-1;
        while(RowS <= RowE)
        {
            int RowMid =(RowE+RowS)/2;
            if(matrix[RowMid][ColS]== target || matrix[RowMid][ColE]== target)return true;

            if(matrix[RowMid][ColS] < target && matrix[RowMid][ColE] <target )
            {
                RowS =RowMid+1;
            }
            else if(matrix[RowMid][ColS] > target && matrix[RowMid][ColE] >target )
            {
                RowE = RowMid-1;
            }
            else
            {
                while(ColS <= ColE)
                {
                    int ColMid = (ColS+ColE)/2;
                    if(matrix[RowMid][ColMid]== target) return true;
                    else if(matrix[RowMid][ColMid] < target)
                    {
                        ColS = ColMid+1;
                    }
                    else
                    {
                        ColE=ColMid-1;
                    }
                }
            }
        }
        return false;
    }
};