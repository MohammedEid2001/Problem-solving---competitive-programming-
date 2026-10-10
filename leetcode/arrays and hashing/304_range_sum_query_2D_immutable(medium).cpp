
/*

description:
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
*/    

//to make it work, we first make a sum 2D array, where each element sum[x][y] is the result of summing all elements in the rectangle from sum[0][0]to sum[x][y] , its done by starting from first element, then recursivly adding the sum of the past smaller rectangles and adding them step by step ( O(x*y)).
//later , if we want the sum of the specific rectangle from x1,y1 to x2,y2, we can simply do it using simple venn diagram relation: the sum of area from 0,0 to x2,y2 - the sum of area above the one we need ( 0,0 > x1-1,y2) - the area left of the area we need(0,0 > x2,y1-1) + the area that got excluded twice( 0,0 > x1-1,y1-1)
//after that 
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        this->sum = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1,0));
        for(int i = 1; i <= matrix.size();++i)
    {
        for(int j = 1; j<=matrix[0].size();++j)
        {
            sum[i][j]= matrix[i-1][j-1] + sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    }      
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
vector< vector<int> > sum;
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */