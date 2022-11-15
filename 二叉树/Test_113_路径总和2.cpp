#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right) :val(x),left(left),right(right) {}
};

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void travelNode(TreeNode *cur,int count)
    {
        if(!cur->left&&!cur->right&&count==0)
        {
            res.push_back(path);
        }

        if(!cur->left&&!cur->right)     // 遇到叶子节点而没有找到合适的边，直接返回
            return ;
        if(cur->left)
        {
            path.push_back(cur->left);
            count -=cur->left->val;
            travelNode(cur->left,count);
            count += cur->left->val;
            path.pop_back();
        }
        if(cur->right)
        {
            path.push_back(cur->right);
            count -=cur->right->val;
            travelNode(cur->right,count);
            count += cur->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        if(root==NULL) 
            return res;
        path.push_back(root->val);
        travelNode(root,targetSum-root->val);
        return res;
    }
};