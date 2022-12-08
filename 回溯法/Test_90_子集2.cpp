#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void backtracking(vector<int>&nums,int startIndex,vector<bool>&used)
    {
        //空子集自身
        res.push_back(path);
        for(int i=startIndex;i<nums.size();i++)
        {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        res.clear();
        path.clear();
        sort(nums.begin(),nums.end());
        backtracking(nums,0,used);
        return res;
    }
};