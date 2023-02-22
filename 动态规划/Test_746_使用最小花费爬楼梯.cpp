#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp[3];
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++)
        {
            dp[2] = min(dp[1]+cost[i-1],dp[0]+cost[i-2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};