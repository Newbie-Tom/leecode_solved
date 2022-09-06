#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;



// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<int,int>Hs,Ht;    // 新建两个哈希表
//         for(int i=0;i<t.size();i++)
//             Ht[t[i]]++;
//         int cnt=0;
//         string st;
//         for(int i=0,j=0;j<s.size();j++) //定义两个指针遍历s
//         {   
//             Hs[s[j]]++; //将遍历s的信息记录在Hs哈希表中
//             //判断i,j是否符合标准
//             if(Hs[s[j]]<=Ht[s[j]]) {
//                 cnt++;               
//             }
//             //不满足条件
//             while (Hs[s[i]]>Ht[s[i]])   //Hs的记录比Ht的多时
//             {
//                 Hs[s[i++]]--;   //更新左边界
//             }
//             if(cnt==t.size())  //当Hs中的满足了
//             {
//                 if(st.empty()||(j-i+1)<st.size())
//                     st=s.substr(i,j-i+1);
//             }
            
//         }
//         return st;
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,Window;
        string res;
        int left=0,right=0;
        int valid=0;
        int len=INT32_MAX;
        int start=0;
        for(auto c:t)need[c]++;

        while (right<s.size())
        {
            char c = s[right];
            right++;
            if(need.count(c))
            {
                Window[c]++;
                if(need[c]==Window[c])
                    valid++;
            }

            while (need.size()==valid)
            {
                if(right-left<len)
                {
                    len = right-left;
                    start=left;
                }
                char d = s[left];
                left++;
                if(need.count(d))
                {
                    if(need[d]==Window[d])
                        valid--;
                    Window[d]--;
                }
            }
            
        }
        return len==INT32_MAX?"":s.substr(start,len);
    }
};

int main()
{
    string s="cabwefgewcwaefgcf";
    string t="cae";
    Solution so;
    string st;
    st=so.minWindow(s,t);
    cout<<st<<endl;
    // for(auto c:st)  cout<<st[c]<<endl;
    return 0;
}