#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void backtracking(vector<int>& candidates, int target,int sum,int startIndex)
    {
        if(sum==target)
        {
            res.push_back(path);
            return;
        }

        for(int i=startIndex;i<candidates.size()&&sum+candidates[i]<=target;i++)   //上限是candidates数组内无限选取
        {
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);// 不用i+1了，表示可以重复读取当前的数
            path.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0);
        return res;
    }
};