#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>window;
        int left =0,right =0;
        int res=0;
        while (right<s.size())
        {
            char c = s[right];
            right++;
            window[c]++;

            while (window[c]>1)
            {
                char d= s[left];
                left++;
                window[c]--;
            }
            res = max(res,right-left);
        }
        return res;
    }
};

int main()
{
    string s = "pwwkew";
    Solution so;
    int res = so.lengthOfLongestSubstring(s);
    cout<<res<<endl;
}