#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        unordered_map<int,int>uMap;
        int res;
        for(int i=0;i<nums.size();i++)
        {
            uMap[nums[i]]++;
        }
        for(auto iter:uMap)
        {
            if(iter.second==1)
            {
                res = iter.first;
                break;
            }    
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = nums[0];
        if(nums.size()>1)
        {
            for(int i=1;i<nums.size();i++)
            {
                res = res^nums[i];
            }
        }
        
        return res; 
    }
};