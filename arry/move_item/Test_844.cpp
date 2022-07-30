#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_tailpointer =s.size()-1;    //定义一个s的尾指针
        int t_tailpointer =t.size()-1;    //定义一个t的尾指针
        int skips = 0,skipt=0;   //跳过标志符
        while(s_tailpointer>=0||t_tailpointer>=0)
        {
            while (s_tailpointer>=0)
            {
                if(s[s_tailpointer]=='#')
                {
                    s_tailpointer--;
                    skips++;
                }   
                else if(skips>0)
                {
                    s_tailpointer--;
                    skips--;
                }
                else
                {
                    break;  //比较   
                }
            }
            while (t_tailpointer>=0)
            {
                if(t[t_tailpointer]=='#')
                {
                    t_tailpointer--;
                    skipt++;
                }   
               else if(skipt>0)
                {
                    t_tailpointer--;
                    skipt--;
                }
                else
                {
                    break;  //比较   
                }
            }
            if(s_tailpointer>=0&&t_tailpointer>=0)
            {
                if(s[s_tailpointer]!=t[t_tailpointer])
                {
                    return false;
                }    
                
            }
            else if (s_tailpointer>=0||t_tailpointer>=0) {
                
                {
                    return false;       
                }
                
            }
            s_tailpointer--;
            t_tailpointer--;            
        }
        return true;

    }
};

int main()
{
    string s= "a##c";
    string t ="#a#c";
    Solution so;
    // if(s==t)
    //    cout<<"tue"<<endl; 
    // else
    //     cout<<"false"<<endl;
    // cout<<s<<endl;
    // cout<<s[0]<<endl;
    cout<<so.backspaceCompare(s,t)<<endl;
}