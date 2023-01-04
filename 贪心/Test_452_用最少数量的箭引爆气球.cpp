#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        //先按照气球的xStart进行排序
        sort(points.begin(),points.end(),cmp);
        //气球非空,则至少需要一支箭
        int res = 1;
        for(int i=1;i<points.size();i++)
        {
            //气球i和i-1不挨着
            if(points[i][0]>points[i-1][1]) 
                res++;
            else{   //气球i和i-1挨着
                points[i][1]=min(points[i-1][1],points[i][1]);  //更新右边界
            }
        }

        return res;
    }   
};