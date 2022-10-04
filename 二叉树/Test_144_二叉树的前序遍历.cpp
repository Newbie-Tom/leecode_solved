#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &res)
    {
        if (cur == NULL)
            return;

        res.push_back(cur->val);
        traversal(cur->left, res);
        traversal(cur->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

//迭代
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode *> stTree;
        stTree.push(root);
        while (!stTree.empty())
        {
            TreeNode *node = stTree.top();
            stTree.pop();
            res.push_back(node->val);
            if(node->right) stTree.push(node->right);  
            if(node->left) stTree.push(node->left);             
        }
        return res;
    }
};