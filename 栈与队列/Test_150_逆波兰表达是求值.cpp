#include <iostream>
#include <stack>
#include <vector>
#include <ctype.h>
#include <string>
using namespace std;



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stValue;
        for(int i=0;i<tokens.size();i++)
        {    
            if(tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="+"||tokens[i]=="-")
            {
                int a = stValue.top();
                stValue.pop();
                int b = stValue.top();
                stValue.pop();
                if(tokens[i]=="*")
                    stValue.push((long)b*a);
                else if(tokens[i]=="/")
                    stValue.push(b/a);
                else if(tokens[i]=="+")
                    stValue.push(b+a);
                else if(tokens[i]=="-")
                    stValue.push(b-a);
            }
            //是数字则入栈
            else 
                stValue.push(stoi(tokens[i]));
        }
        return (int)stValue.top();
    }
};


int main()
{
    vector<string> res{"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    Solution so;
    cout<<so.evalRPN(res);
    return 0;
}