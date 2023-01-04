#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0}; //i为字符,hash[i]为字符最后出现的位置
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a'] = i; //统计每个字符的最后出现位置
        }
        vector<int>res;
        int left = 0;
        int right = 0;
        for(int i=0;i<s.size();i++)
        {
            // 找到字符出现的最远边界
            right = max(right,hash[s[i]-'a']);
            if(i==right)
            {
                res.push_back(right-left+1);
                left = right+1;
            }
        }
        return res;
    }
};