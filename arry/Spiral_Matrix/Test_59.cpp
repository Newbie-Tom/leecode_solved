#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;



// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         //创建一个n行n列的二维矩阵
//         vector<vector<int>> res(n, vector<int>(n,0));
//         //圈数
//         int loop = n/2;
//         //确定起始坐标
//         int startx=0,starty=0;
//         int count=1;
//         //跟随圈的数增大,圈数越多,偏移量越大
//         int offset=1;
//         //用于边界的确定
//         int i=0,j=0;
//         //正整数n需要走n/2圈,各边界确定为左闭右开
//         while (loop--)
//         {
//             //上边界从左往右
//             for(j=starty;j<n-offset;j++)
//                res[startx][j]=count++;
//             //右边界从上到下
//             for(i=startx;i<n-offset;i++)
//                 res[i][j]=count++;
//             //下边界从右往左
//             for(;j>starty;j--)
//                 res[i][j]=count++;
//             //左边界从下往上
//             for(;i>startx;i--)
//                 res[i][j]=count++;
            
//             //若开始第二圈则起始坐标迁移至(1,1)
//             startx++;
//             starty++;
//             offset++;
//         }
//         //n若为奇数,中心点单独赋值
//         if(n%2==1)
//             res[n/2][n/2]=count;
        
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        //定义一个新的二维矩阵
        vector<vector<int>> res(n,vector<int>(n,0));
        int u=0;
        int d = res.size()-1;
        int l = 0;
        int r = res[0].size()-1;
        int count=1;
        while (true)
        {
            for(int i = l;i<=r;i++)
                res[u][i] = count++;
            if(++u>d) break;    //将上边加1,避免最后数重合
            
            for(int i=u;i<=d;i++)
                res[i][r] = count++;
            if(--r<l) break;

            for(int i=r;i>=l;i--)
                res[d][i]=count++;
            if(--d<u) break;

            for(int i=d;i>=u;i--)
                res[i][l]=count++;
            if(++l>r) break;
        }
        return res;
    }
};


int main()
{
    int martix = 3;
    vector<vector<int>> res(martix,vector<int>(martix,0));
    Solution so;
    res = so.generateMatrix(3);

    for(int i=0;i<martix;i++)
        for(int j=0;j<martix;j++)
            cout<<res[i][j]<<endl;

    return 0;
}