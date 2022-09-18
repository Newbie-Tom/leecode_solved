#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        int oldSize=s.size();
        int spaceNum=0;
        for(auto x:s)
        {    
                if(x==' ')
                        spaceNum++;
        } 
        spaceNum*=2;
        int newSize=oldSize+spaceNum;
        s.resize(newSize);
        string s2(s);
        int fast=0,slow=0;
        for(int i=fast;i<oldSize;i++)
        {
                if(s2[i]!=' ')
                {
                        s[slow++]=s2[i];
                }
                else 
                {
                      s[slow++]='%';
                      s[slow++]='2';
                      s[slow++]='0';  
                }
        }
        return s;
    }
};