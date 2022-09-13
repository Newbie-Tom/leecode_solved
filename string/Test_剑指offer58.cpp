#include  <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
        void  reverse(string &s,int start,int end)
        {
                for(int i=start,j=end;i<j;i++,j--)
                {
                        swap(s[i],s[j]);
                }
        }
        string reverseLeftWords(string s, int n) {
                //1、翻转前n个子字符串
                reverse(s,0,n-1);
                //2、翻转n到s字符串尾
                reverse(s,n,s.size()-1);
                //3、翻转整个字符串
                reverse(s,0,s.size()-1);
                return s;
        }
};

int main()
{
        string s = "lrloseumgh";
        int k=6;
        Solution so;
        cout<<so.reverseLeftWords(s,k)<<endl;
        return 0;
}