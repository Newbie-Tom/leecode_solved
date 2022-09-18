#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
        string  removeExtraSpace(string s)
        {
                int slow=0;
                for(int i=0;i<s.size();i++)
                {
                        if(s[i]!=' ')
                        {
                                if(slow!=0) 
                                        s[slow++]=' ';
                                while (s[i]!=' '&&i<s.size())
                                {
                                        s[slow++]=s[i++];
                                }
                                
                        }
                }
                s.resize(slow);
                return s;
        }
        void reverse(string &s,int start,int end)
        {
                for(int i=start,j=end;i<=j;i++,j--)
                {
                        swap(s[i],s[j]);
                }
        }
    string reverseWords(string s) {
        /*
        *@三步走
        *1、去除多余括号
        *2、整体翻转
        *3、逐词翻转
        */
        s = removeExtraSpace(s);
        int start=0,end=s.size()-1;
        reverse(s,start,end);
        int slow=0;
        for(int i=0;i<=s.size();i++)
        {
                if(s[i]==' '||i==s.size())
                {
                        reverse(s,slow,i-1);
                        slow=i+1;
                }
        }
        return s;
    }
};

int main()
{
        Solution so;
        string s="  hello world  ";
        
        cout<<so.reverseWords(s)<<endl;
        return 0;
}