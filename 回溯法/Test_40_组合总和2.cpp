#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;    //存放组合集合
    vector<int>path;    //符合条件的集合
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex,vector<bool>&used)
    {
        //终止条件
        if(sum==target)
        {
            res.push_back(path);
            return ;
        }
        for(int i=startIndex;i<candidates.size()&&sum+candidates[i]<=target;i++)
        {
            //used[i-1]==true,说明同一树枝candidates[i-1]使用过
            //used[i-1]==false,说明同一树层candidates[i-1]使用过
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false)
            {
                continue;
            }
            sum+=candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates,target,sum,i+1,used);
            used[i] = false;
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<bool> used(candidates.size(),false);
        res.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
        return res;
    }
};