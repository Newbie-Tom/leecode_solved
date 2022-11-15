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
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right) {}
};

//中序
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL) return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if(cur!=NULL)
            {
                st.pop();   //避免重复操作
                if(cur->right) st.push(cur->right);
                st.push(cur);
                st.push(NULL);
                if(cur->left)  st.push(cur->left);
            }
            else
            {
                st.pop();   //先弹出空节点
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }
};

//前序
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL)return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if(cur!=NULL)
            {
                st.pop();   //出栈
                if(cur->right) st.push(cur->right); //右子结点先入栈
                if(cur->left) st.push(cur->left);
                st.push(cur);
                st.push(NULL);
            }
            else
            {
                st.pop();
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }    
        return result;
    }
};

//后序
class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL)return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();   //中
            if(cur!=NULL)
            {
                st.pop();   //避免重复操作
                st.push(cur);
                st.push(NULL);
                if(cur->right) st.push(cur->right);
                if(cur->left)  st.push(cur->left);
            }
            else
            {
                st.pop();
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
            }
        }
        
        return result;
    }
};