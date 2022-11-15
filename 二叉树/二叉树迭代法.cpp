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
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};
//前序(根左右)
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL)return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();   //中
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right); //右
            if(cur->left) st.push(cur->left);   //左         
        }
        return result;
    }
};
//后序(左右根)
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
            st.pop();     
            result.push_back(cur->val);   
            if(cur->left) st.push(cur->left);   //左  
            if(cur->right) st.push(cur->right); //右
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

//中序
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL) return result;
        TreeNode *cur = root;
        while (cur!=NULL||!st.empty())
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else{
                //此时cur为空,得先弹栈再入vector
                cur = st.top(); 
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};