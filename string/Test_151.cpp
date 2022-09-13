#include  <iostream>
#include <algorithm>
#include <vector>
using  namespace std;


class Solution {
public:
        void reverse(string  &s,int start,int end)
        {
                for(int i=start,j=end;i<j;i++,j--)
                {
                        swap(s[i],s[j]);
                }        
        }
        void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                if(slow!=0)
                    s[slow++]=' ';
                while (i<s.size()&&s[i]!=' ')
                    s[slow++]=s[i++];
                
            }
        }
        s.resize(slow);
}
    string reverseWords(string s) {
        //1、先去除多余空格
        //进行双指针法，把头和尾的空格去掉
        removeExtraSpaces(s);
        //2、翻转字符串
        int left =0,right = s.size()-1;
        reverse(s,left,right);

        int start=0;
        for(int i=0;i<=s.size();i++)
        {
                if(i==s.size()||s[i]==' ')
                {
                        reverse(s,start,i-1);
                        start=i+1;
                }
                
        }
        return s;
    }
};

int main()
{
        string s = "  hello world  ";
        Solution so;
        cout<<so.reverseWords(s)<<endl;
        return 0;
}