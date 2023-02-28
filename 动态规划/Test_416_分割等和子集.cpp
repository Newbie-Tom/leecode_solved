#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        //1 <= nums.length <= 200
        //1 <= nums[i] <= 100
        vector<int>dp(10001,0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)        //如果有余数,则不能分割成两个子集
            return false;
        int target = sum/2;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=target;j>=nums[i];j--)
            {
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target]==target) 
            return true;
        return false;
    }
};

int main()
{
    Solution so;
    vector<int>nums = {1, 5, 11, 5};
    cout<<so.canPartition(nums)<<endl;
    return 0;
}