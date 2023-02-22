#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        int res = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=i;i<s.size();j++)
            {
                if(s[i]==s[j])  //两种情况
                {
                    if(j-i<=1)
                    {
                        res++;
                        dp[i][j]=true;
                    }
                    else if(dp[i+1][j-1])
                    {
                        res++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return res;
    }
};