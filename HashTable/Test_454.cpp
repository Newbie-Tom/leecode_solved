#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;



class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int,int>uMap;
        for(auto a:nums1)
        {
            for(auto b:nums2)
            {
                uMap[a+b]++;
            }
        }
        for(auto c:nums3)
        {
            for(auto d:nums4)
            {
                auto iter = uMap.find(0-c-d);
                if(iter!=uMap.end())
                {
                    
                    count+=uMap[0-c-d];
                }
            }
        }
        return count;
    }
};
