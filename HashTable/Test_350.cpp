#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int>uMap;
        for(auto num:nums1) uMap[num]++;
        for(auto num:nums2) {
            if(uMap.count(num)&&uMap[num]>0)
            {
                uMap[num]--;
                res.push_back(num);
            }               
        }
        return res;
    }
};
