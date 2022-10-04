#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归法
class Solution {
public:
    void travelsal(TreeNode *cur,vector<int>&res)
    {
        if(cur==NULL) return ;
        travelsal(cur->left,res);
        res.push_back(cur->val);
        travelsal(cur->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        travelsal(root,res);
        return res;
    }
};


//迭代法
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return res;
        stack<TreeNode *>st;
        TreeNode *node = root;
        while (node||!st.empty())
        {
            if(node){
                st.push(node);
                node = node->left;
            }   
            else{
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
