#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        // 终止条件
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums,used);
        return res;
    }
};