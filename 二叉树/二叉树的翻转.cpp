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
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right){}
};

//递归法
class Solution {
public:
    void inverse(TreeNode *cur)
    {
        if(cur==NULL) return ;//终止条件
        swap(cur->left,cur->right);
        inverse(cur->left);
        inverse(cur->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        inverse(root);
        return root;
    }
};

//前序迭代法
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode *>st;
        if(root==NULL) return root;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur =  st.top();
            st.pop();
            swap(cur->left,cur->right);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left); 
        }
        return root;
    }
};

//统一迭代法 前序
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode *>st;
        if(root==NULL) return root;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            if(cur!=NULL)
            {
                st.pop();   //先弹出,避免重复操作     
                if(cur->right) st.push(cur->right);
                if(cur->left) st.push(cur->left);
                st.push(cur);
                st.push(NULL);
            }
            else
            {
                st.pop();
                cur = st.top();
                st.pop();
                swap(cur->left,cur->right);
                
            }
        }
        return root;
    }
};

//层序遍历法

class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>qu;
        if(root==NULL) return root;
        qu.push(root);
        while (!qu.empty())
        { 
            int size = qu.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = qu.front();
                qu.pop();
                swap(cur->left,cur->right);
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
                
            }    
        }
        
        return root;
    }
};
