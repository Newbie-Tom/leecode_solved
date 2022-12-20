#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//斐契那波数列
class Solution {
public:
    int climbStairs(int n) {
        double b = sqrt(5);
        double fib = pow((1+b)/2,n+1)-pow((1-b)/2,n+1);
        return (int)round(fib/b);
        
    }
};
//递归
class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=1)
            return n;
        int dp[3];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int sum = dp[1]+dp[2];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};