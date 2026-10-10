
/*
description:
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

// make seperate functions to check for rows/coloumns/blocks

class Solution {
public:

    bool CheckB( vector< vector<char>> & board, vector<bool> & Block, int index)
    {
        bool valid = true;
        int starting = int(index/3)*27+ (index%3)*3;
        for(int i = 0; i<3 && valid;++i)
        {
            for(int j = 0; j<3 && valid; ++j){
                int current = starting + i + 9*j;
                int x = current/9;
                int y = current % 9;
                if(board[x][y] != '.')
                {
                    if(Block[board[x][y]-'0'])valid = false;
                    Block[board[x][y]-'0']= true;
                }
            }
        }
        return valid;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        vector<bool> CheckRows(10,0);
        vector<bool> CheckCols(10,0);
        vector<bool> CheckBlocks(10,0);
        for(int i = 0 ; i<board.size() &&valid ; ++i)
        {
            CheckRows.assign(10,0);
            CheckCols.assign(10,0);
            CheckBlocks.assign(10,0);
            if(!CheckB(board, CheckBlocks,i))valid = false;
            for(int j = 0; j < board[i].size() && valid; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(CheckRows[board[i][j]-'0'])valid = false;
                    CheckRows[board[i][j]-'0' ] =true;
                }
                if(board[j][i] != '.')
                {
                    if(CheckCols[board[j][i]-'0'])valid = false;
                    CheckCols[board[j][i]-'0']=true;
                }
                
            }
        }
        return valid;
    }
};