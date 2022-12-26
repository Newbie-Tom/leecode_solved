#include <iostream>
using namespace std;


class Solution {
public:
    bool isValid(string s,int start,int end)
    {
        while (start<end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {

    }
};


int main()
{
    Solution so;
    string s = "abbac";
    cout<<so.isValid(s,0,s.size()-1);
    return 0;
}