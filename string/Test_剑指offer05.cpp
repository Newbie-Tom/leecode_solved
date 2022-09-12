#include  <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
private:
        int spaceNum(string s){
                int count=0;
                for(int i=0;i<s.size();i++)
                        if(s[i]==' ')
                                count++;
                return count;
        }
public:
    string replaceSpace(string s) {
        //空格数量，替换成%20,需要多申请count的空间
        int count = spaceNum(s);
        int oldSize = s.size()-1;
        s.resize(s.size()+count*2);
        int left = oldSize,right=s.size()-1;
        for(int i=left,j=right;i<j;i--,j--)
        {
                if(s[i]!=' ')
                {
                        s[j]=s[i];
                        
                }        
                else{
                        s[j]='0';
                        s[--j]='2';
                        s[--j]='%';
                        
                }
        }
        return s;
    }
};


int main()
{
        Solution so;
        string s ="We are happy";
        cout<<so.replaceSpace(s)<<endl;
        return 0;
}