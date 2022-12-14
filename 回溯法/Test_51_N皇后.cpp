#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include<map>
using namespace std;


class Solution {
        private:
        //合法性
        bool isValid(int row,int col,vector<string>&chessboard,int n)
        {
                //判断同列
                for(int i=0;i<row;i++)
                {
                        if(chessboard[i][col]=='Q')
                                return false;
                }
                //判断45度
                for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
                {
                        if(chessboard[i][j]=='Q')
                                return false;
                }
                //判断135度
                for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
                {
                        if(chessboard[i][j]=='Q')
                                return false;
                }
                return true;
        }
public:
        vector<vector<string>>res;
        void backtracking(int n,int row,vector<string>&chessboard)
        {
                //终止条件
                if(row==n)
                {
                        res.push_back(chessboard);
                        return;
                } 
                for(int col=0;col<n;col++)
                {
                        if(isValid(row,col,chessboard,n))       //剪枝
                        {
                                chessboard[row][col]  = 'Q';
                                backtracking(n,row+1,chessboard);
                                chessboard[row][col]  = '.';
                        }
                }   
        }
        vector<vector<string>> solveNQueens(int n)
        {
                res.clear();
                vector<string>chessboard(n,string(n,'.'));
                backtracking(n,0,chessboard);
                return res;
        }
};