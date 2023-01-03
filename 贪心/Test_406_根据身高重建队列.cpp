#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

//vector实现
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])  
            return a[1]< b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>que;
        for(int i=0;i<people.size();i++)
        {
            int index = people[i][1];
            que.insert(que.begin()+index,people[i]);
        }
        return que;
    }
};

//链表实现
class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])  
            return a[1]< b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        list<vector<int>>que;   //list底层是链表实现，插入效率比vector高的多
        for(int i=0;i<people.size();i++)
        {
            int index = people[i][1];
            std::list<vector<int>>::iterator it  = que.begin();
            while (index--)
            {
                it++;
            }
            que.insert(it,people[i]);
        }
        return vector<vector<int>>(que.begin(),que.end());
    }
};