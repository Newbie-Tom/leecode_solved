#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//大饼干喂饱大胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = s.size()-1;
        int res=0;
        for(int i=g.size()-1;i>=0;i--)
        {
            if(index>=0&&s[index]>=g[i])
            {
                res++;
                index--;
            }

        }
        return res;

    }
};
//小饼干喂饱小胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index = 0;
        for(int i=0;i<s.size();i++)
        {
            if(index<g.size()&&g[index]<=s[i])
            {
                index++;
            }
        }
        return index;
    }
};
