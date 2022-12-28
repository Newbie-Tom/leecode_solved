#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=0;
        int res=INT32_MIN;
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i];
            if(count>res)   // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                res = count;
            if(count<=0) count=0;
        }
        return res;
    }
};