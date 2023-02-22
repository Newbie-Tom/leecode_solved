#include  <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<2)
            return n;
        vector<int> dp(3);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
        {
            int sum = dp[1]+dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};