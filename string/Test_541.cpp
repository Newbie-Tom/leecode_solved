#include  <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// class Solution {
//     private:
//     void reverse(string &s,int left,int right)
//     {
//         for(int i=left,j=right;i<j;i++,j--)
//             swap(s[i],s[j]);
//     }
// public:
//     string reverseStr(string s, int k) {
//         for(int i=0;i<s.size();i+=2*k)
//         {
//             //1、每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符
//             //2、如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
//             if(i+k<s.size()){
//                 reverse(s,i,i+k-1);
//                 continue;
//             }
//             //3、如果剩余字符少于 k 个，则将剩余字符全部反转。
//                 reverse(s,i,s.size()-1);
//         }
//         return s;
//     }
// };

class Solution {
    private:
    void reverse(string &s,int left,int right)
    {
        for(int i=left,j=right;i<j;i++,j--)
            swap(s[i],s[j]);
    }
public:
    string reverseStr(string s, int k) {
        int i=0,j=s.size();
        while (i<j)
        {
            if(i+k<j){
                reverse(s,i,i+k-1);
            }
            else
                reverse(s,i,s.size()-1);
            i+=2*k;
        }
        return s;
    }
};

int main()
{
    string s = "abcd";
    int k=4;
    Solution so;
    cout<<so.reverseStr(s,k)<<endl;
    return 0;
}






