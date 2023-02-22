#include  <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        vector<int>dp(n+1,0);   //N+1:0~N
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        vector<int>dp(2);  
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int sum = dp[0]+dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main()
{
    int n = 2;
    Solution so;
    cout<<so.fib(n)<<endl;
}