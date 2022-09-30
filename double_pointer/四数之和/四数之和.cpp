
#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        //排序
        sort(nums.begin(),nums.end());
        //套两层循环
        for(int i=0;i<nums.size();i++)  //a
        {
                if(nums[i]>target&&(nums[i]>=0||target>=0))
                break;
                //去重
                if(i>0&&nums[i]==nums[i-1])
                        continue;
                for(int j=i+1;j<nums.size();j++)  //b
                {
                        if(nums[i]+nums[j]>target&&(nums[i]+nums[j]>=0||target>=0))
                                break;
                        //去重
                        if(j>i+1&&nums[j]==nums[j-1])
                                continue;
                        int  left = j+1,right = nums.size()-1;
                        while (left<right)
                        {
                                if((long)nums[i]+nums[j]+nums[left]+nums[right]==target)
                                {
                                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                                        while (left<right&&nums[left]==nums[left+1])    left++;
                                        while (left<right&&nums[right]==nums[right-1])    right--;
                                        left++;
                                        right--;        
                                }
                                else if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)
                                        right--;
                                else
                                        left++;        
                                
                        }
                                 
                }                       
        }
        return res;
    }
};
