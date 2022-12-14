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
    void backtracking(vector<int>&nums,int startIndex)
    {
        //递增子序列至少两个元素
        if(path.size()>1)
        {
            res.push_back(path);
        }
        unordered_set<int>uSet;
        for(int i=startIndex;i<nums.size();i++)
        {
            /*
            *path路径非空
            *当前的数值比序列最后一个数值小
            *无序集合set找到了此数值
            */
            if((!path.empty()&&nums[i]<path.back())||(uSet.find(nums[i])!=uSet.end()))
            {
                continue;
            }
            uSet.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        res.clear();
        path.clear();
        backtracking(nums,0);
        return res;
    }
};
//用数组的方法
class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    void backtracking(vector<int>&nums,int startIndex)
    {
        if(path.size()>1)
        {
            res.push_back(path);

        }
        int used[201]={0};  //这里使用数组来进行去重操作，题目说数值范围[-100, 100]
        for(int i=startIndex;i<nums.size();i++)
        {
            /*
            *path路径非空
            *当前的数值比序列最后一个数值小
            *无序集合set找不到此数值
            */
            if((!path.empty()&&nums[i]<path.back())||used[nums[i]+100]==1)
            {
                continue;
            }
            used[nums[i]+100]=1;
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        res.clear();
        path.clear();
        backtracking(nums,0);
        return res;
    }
};
