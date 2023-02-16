#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// unordered_map做法
// class Solution {
// public:
//         int majorityElement(vector<int>& nums) {
//                 // 初始化
//                 unordered_map<int,int>uMap;
//                 int i=0;  pair<int,int>res={0,0};
//                 for(int i=0;i<nums.size();i++)
//                 {
//                         uMap[nums[i]]++;
//                 }
//                 for(auto it=uMap.begin();it!=uMap.end();it++)
//                 {
//                         if(it->second>res.second)
//                         {
//                                 res.first=it->first;
//                                 res.second = it->second;
//                         }
//                 }
//                 return res.first;
//         }
// };

//排序 
class Solution {
public:
        int majorityElement(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                return nums[nums.size()/2];
        }
};


int main()
{
        vector<int> nums ={3,2,3};
        Solution so;
        cout<<so.majorityElement(nums)<<endl;
}