#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //按照右边界从小到大排序
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count=1;    //记录非交叉区间的个数,默认为一个
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            //一旦非交叉的元素,就个数加1,且更新end
            if(intervals[i][0]>=end)
            {
                count++;
                end = intervals[i][1]; 
            }
        }
        return intervals.size()-count;
    }
};