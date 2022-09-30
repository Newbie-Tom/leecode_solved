#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        //1、先排序
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
                //如果第一位>0，则数组不可能有三元数组
                if(nums[i]>0)
                        break;       
                //去重,按照i和i-1
                if(i>0&&nums[i]==nums[i-1])
                        continue;
                //2、定义两个指针，left,right，分别指向第i+1位和最后一位
                int left=i+1,right = nums.size()-1;
                while (left<right)
                {
                        //如果正好等于0，可以将其记录
                        if(nums[i]+nums[left]+nums[right]==0)
                        {
                                res.push_back({nums[i],nums[left],nums[right]});
                               // 收录后，对b和c去重
                                while (left<right&&nums[left]==nums[left+1]) left++;
                                while (left<right&&nums[right]==nums[right-1]) right--;
                                //将b和c都进行移位
                                left++;
                                right--;
                        }
                        //偏大，则right左移
                        else if(nums[i]+nums[left]+nums[right]>0)
                                right--;
                        //偏小，left右移
                        else if(nums[i]+nums[left]+nums[right]<0)
                                left++;
                }
                
                
        }
        return res;
    }
};