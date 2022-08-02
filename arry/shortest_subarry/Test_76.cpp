#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;



class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int>Hs,Ht;    // 新建两个哈希表
        for(int i=0;i<t.size();i++)
            Ht[t[i]]++;
        int cnt=0;
        string st;
        for(int i=0,j=0;j<s.size();j++) //定义两个指针遍历s
        {   
            Hs[s[j]]++; //将遍历s的信息记录在Hs哈希表中
            //判断i,j是否符合标准
            if(Hs[s[j]]<=Ht[s[j]]) {
                cnt++;               
            }
            //不满足条件
            while (Hs[s[i]]>Ht[s[i]])   //Hs的记录比Ht的多时
            {
                Hs[s[i++]]--;   //更新左边界
            }
            if(cnt==t.size())  //当Hs中的满足了
            {
                if(st.empty()||(j-i+1)<st.size())
                    st=s.substr(i,j-i+1);
            }
            
        }
        return st;
    }
};

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    Solution so;
    string st;
    st=so.minWindow(s,t);
    for(auto c:st)  cout<<st[c]<<endl;
    return 0;
}