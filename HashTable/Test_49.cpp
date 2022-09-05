#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {       
        vector<vector<string>> nums2;
        unordered_map<string,vector<string>>uMap;
        for(vector<string>::iterator iter = strs.begin();iter!=strs.end();iter++)
        {
            string key = *iter;
            sort(key.begin(),key.end());
            uMap[key].push_back(*iter);
        }
        for(auto &x:uMap)
        {
            nums2.push_back(x.second);
        }
        return nums2;
    }
};


