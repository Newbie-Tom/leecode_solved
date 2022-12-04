#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
    private:
        bool ispalindrome(string s,int begin,int end)
        {
            while (begin<end)
            {
                if(s[begin]!=s[end])
                    return false;
                begin++;
                end--;
            }
            return true;
        }
    public:
        vector<vector<string>>res;
        vector<string>path;
        void backtracking(string s,int startIndex)
        {
            //终止条件,即指针遍历到字符串s尾
            if(startIndex>=s.size())
            {
                res.push_back(path);
                return;
            }
            for(int i=startIndex;i<s.size();i++)
            {
                if(ispalindrome(s,startIndex,i))
                {
                    string str = s.substr(startIndex,i-startIndex+1);
                    path.push_back(str);
                }
                else
                    continue;
                //回溯
                backtracking(s,i+1);
                path.pop_back();
            }
        }
        vector<vector<string>> partition(string s) 
        {
            res.clear();
            path.clear();
            backtracking(s,0);
            return res;
        }
};