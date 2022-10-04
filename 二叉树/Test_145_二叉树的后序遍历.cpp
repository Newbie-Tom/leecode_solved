#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 递归
class Solution
{
public:
    void travelsal(TreeNode *cur, vector<int> &res)
    {
        if (cur == NULL)
            return;
        travelsal(cur->left, res);
        travelsal(cur->right, res);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        travelsal(root, res);
        return res;
    }
};

// 迭代
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int>res;
        if(root==NULL) return res;
        stack<TreeNode *>st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;    
    }
};