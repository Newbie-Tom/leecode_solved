#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);   //dp[i]为i个不同元素组成的二叉搜索树个数
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};