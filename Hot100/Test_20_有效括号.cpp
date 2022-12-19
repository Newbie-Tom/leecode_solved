#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]=='(')
                st.push(')');
            else if(s[i]=='[')
                st.push(']');
            else if(s[i]=='{') 
                st.push('}');
            else {
                if(st.empty()||s[i]!=st.top())
                    return false;
                else
                    st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;

    }
};

