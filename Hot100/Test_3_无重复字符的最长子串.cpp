#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char,int>uMap;
        int left=0,right=0;
        while (right<s.size())
        {
            char c = s[right];
            right++;
            uMap[c]++;
            while (uMap[c]>1)
            {
                char d = s[left];
                left++;
                uMap[d]--;
            }
            res = max(res,right-left);
        }
        return res;
    }
};

int main()
{
    Solution so;
    string s = "dvdf";
    cout<<so.lengthOfLongestSubstring(s)<<endl;
    return 0;
}