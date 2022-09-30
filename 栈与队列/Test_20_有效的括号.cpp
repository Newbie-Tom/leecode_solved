#include <iostream>
#include <stack>
using namespace std;


// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()%2)  return false;
//         stack<char> brckets;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(')
//                 brckets.push(')');
//             else if(s[i]=='{')
//                 brckets.push('}');
//             else if(s[i]=='[')
//                 brckets.push(']');

//             else if(brckets.empty()||brckets.top()!=s[i]) 
//                 return false;
//             else
//                 brckets.pop();
//         }
//         if(!brckets.empty())
//             return false;
//         else
//             return true;
//     }
// };


class Solution {
public:
    bool isValid(string s)
    {
        if(s.size()%2) return false;
        stack<char> brackets;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                brackets.push('(');
            else if(s[i]=='{')
                brackets.push('{');
            else if(s[i]=='[')
                brackets.push('[');
            else if(s[i]==')')
            {
                if(brackets.empty()||brackets.top()!='(')
                    return false;
                else
                    brackets.pop();
            }
            else if(s[i]=='}')
            {
                if(brackets.empty()||brackets.top()!='{')
                    return false;
                else
                    brackets.pop();
            }
            else if(s[i]==']')
            {
                if(brackets.empty()||brackets.top()!='[')
                    return false;
                else
                    brackets.pop();
            }
        }
        return brackets.empty();
    }
};

int main()
{
    Solution so;
    string s = "(){}[]";
    cout<<so.isValid(s)<<endl;
    return 0;
}