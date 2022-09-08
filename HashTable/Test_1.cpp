#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>uMap;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            auto iter = uMap.find(target-nums[i]);
            if(iter !=uMap.end())
                return {i,iter->second};
            uMap.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};

int main()
{
    Solution so;
    vector<int> nums{3,3};
    int target=6;
    for(auto num:so.twoSum(nums,target))
        cout<<num<<endl;
    return 0;
}