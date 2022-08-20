#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using std::min;
using std::vector;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res; //定义一个一维矩阵
        if(matrix.empty())
            return res;
        int u=0;
        int d=matrix.size()-1;
        int l=0;
        int r=matrix[0].size()-1;

        while (true)
        {
            for(int i=l;i<=r;i++)
                res.push_back(matrix[u][i]);
            if(++u>d) break;
            
            for(int i=u;i<=d;i++)
                res.push_back(matrix[i][r]);
            if(--r<l) break;

            for(int i=r;i>=l;i--)
                res.push_back(matrix[d][i]);
            if(--d<u) break;

            for(int i=d;i>=u;i--)
                res.push_back(matrix[i][l]);
            if(++l>r) break;
        }
        return res;        


    }
};

int main()
{
    int martix_row = 3;
    int martix_col = 4;
    int count = 1;
    vector<vector<int>> res(martix_row, vector<int>(martix_col, 0));
    for (int i = 0; i < martix_row; i++)
        for (int j = 0; j < martix_col; j++)
            res[i][j] = count++;
    // vector<vector<int>>res ={{6,9,7}};
    Solution so;
    vector<int> matrix_Demo;
    matrix_Demo = so.spiralOrder(res);
    for (int i = 0; i < matrix_Demo.size(); i++)
        cout << matrix_Demo[i] << endl;
    return 0;
}