#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    void backtracking(vector<int>&nums,vector<bool>&used)
    {
        //终止条件
        if(path.size()==nums.size())
        {
            res.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过 
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
                continue;
            if(used[i]==false){
              path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;  
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool>used(nums.size(),false);
        backtracking(nums,used);
        return res;      
    }
};