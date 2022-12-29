#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=prices.size()-1;i>=1;i--)
        {
            res+=max(prices[i]-prices[i-1],0);
        }
        return res;
    }
};