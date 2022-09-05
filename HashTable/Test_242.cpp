#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        //定义一个数组用于存放26个字符
        // int nums[26]={0};
        vector<int> nums(26);
        //依次把s字符串内的各个字符++
        for(int i=0;i<s.size();i++)
        {
            nums[s[i]-'a']++;
        }
        //依次把t字符串内的各个字符--
        for (int i = 0; i < t.size(); i++)
        {
            nums[t[i]-'a']--;
        }
        // for(int i=0;i<26;i++)
        // {
        //     if(nums[i]!=0)
        //         return false;
        // }
        for(vector<int>::iterator iter = nums.begin();iter != nums.end();iter++)
        {
            if(*iter!=0)
                return 0;
        }
        return true;

    }
};

int main()
{
    string s = "aa";
    string t = "bb";
    Solution so ;
    cout<<so.isAnagram(s,t);
    return 0;
}