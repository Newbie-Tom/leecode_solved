#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //先排序
        sort(nums.begin(),nums.end());
        //定义一个返回的vector
        vector<vector<int>>res;
        //保留三位i,left,right
        for(int k=0;k<nums.size();k++)
        {
            //一重剪枝
            //退出条件
            if(nums[k]>target&&(nums[k]>0))break;
            //去重条件
            if(k>0&&nums[k]==nums[k-1])continue;
            for(int i=k+1;i<nums.size();i++)
            {
                //退出条件
                if(nums[k]+nums[i]>target&&(nums[k]+nums[i]>0||target>0))break;
                //去重条件
                if(i>1&&nums[i]==nums[i-1])continue;
                int left = i+1,right=nums.size()-1;
                while (left<right)
                {
                    long sum = (long)nums[k]+nums[i]+nums[left]+nums[right];
                    if(sum==target){
                        res.push_back({nums[k],nums[i],nums[left],nums[right]});
                        while (left<right&&nums[left]==nums[++left]);
                        while(left<right&&nums[right]==nums[--right]);                        
                    }
                    if(sum>target)  while(left<right&&nums[right]==nums[--right]);
                    if(sum<target)  while (left<right&&nums[left]==nums[++left]);                     
                }
            }
        }
        return res;
    }
};