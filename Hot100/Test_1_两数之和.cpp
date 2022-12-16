#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>uMap;
        vector<int>res;
        if((target>=0&&nums[0]>target)||(target<0&&nums[nums.size()-1]<target))
            return res;
        for(int i=0;i<nums.size();i++)
        {
            auto iter = uMap.find(target-nums[i]);
            if(iter!=uMap.end())
            {
                res.push_back(iter->second);
                res.push_back(i);
                break;
            }    
            uMap.insert(pair<int,int>(nums[i],i));
        }     
        return res;
    }
};

int main()
{
    Solution so;
    vector<int>nums = {3,2,4};
    vector<int>res;
    res = so.twoSum(nums,6);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
    return 0;
}