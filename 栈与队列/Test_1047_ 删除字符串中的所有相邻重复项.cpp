#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> StringList;
        for(int i=0;i<s.size();i++)
        {
            if(StringList.empty()||StringList.top()!=s[i])
                StringList.push(s[i]);
            else
                StringList.pop();
        }
        s.clear();
        if(StringList.empty())
            return "";
        else{
            while (!StringList.empty())
            {
                s.push_back(StringList.top());
                StringList.pop();
            }
            reverse(s.begin(),s.end());
        }
        return s;
    }
};


int main()
{
    Solution so;
    string s = "abbacba";
    cout<<so.removeDuplicates(s)<<endl;
    return 0;
}
