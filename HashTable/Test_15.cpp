#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //先排序
        sort(nums.begin(),nums.end());
        //定义一个二维数组
        vector<vector<int>>res;
        //k作遍历,留i,j两个位置
        for(int k=0;k<nums.size()-2;k++)
        {
            //如果nums[k]>0,直接不成立
            if(nums[k]>0)   break;
            //如果不是地一个数字,后序遍历要考虑去重
            if(k>0&&nums[k]==nums[k-1]) continue;
            //定义左右指针
            int i = k+1,j = nums.size()-1;
            while (i<j)
            {
                int sum = nums[k]+nums[i]+nums[j];
                //如果符合条件,就存入数组中
                if(sum==0){
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i<j&&nums[i]==nums[++i]); 
                    while (i<j&&nums[j]==nums[--j]);
                } 

                //和大于0,右指针后退,同时考虑去重
                else if(sum>0)
                    while (i<j&&nums[j]==nums[--j]);
                //和小于0,左指针前进,同时考虑去重
                else
                    while(i<j&&nums[i]==nums[++i]);    
            }
        }

        return res;
    }
};
