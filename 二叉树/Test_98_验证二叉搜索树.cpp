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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归1
class Solution {
public:
        void TravelNode(TreeNode *cur,vector<int>&res)
        {
                if(cur==NULL)   return ;
                TravelNode(cur->left,res);
                res.push_back(cur->val);
                TravelNode(cur->right,res);
        }
        bool isValidBST(TreeNode* root) 
        {
                if(root==NULL)
                        return true;
                vector<int>res;
                TravelNode(root,res);
                for (int i = 1; i < res.size(); i++)
                {
                        if(res[i]<=res[i-1])
                                return false;
                }
                return true;
        }

};

//递归2
class Solution {
public:
       TreeNode *pre = NULL;
        bool isValidBST(TreeNode* root) 
        {
                if(root==NULL)
                        return true;
                bool left = isValidBST(root->left);
                if(pre!=NULL&&pre->val>=root->val)
                        return false;
                else 
                        pre = root;
                bool right = isValidBST(root->right);
                return left&&right;
        }
};


//迭代
class Solution {
public:
       
        bool isValidBST(TreeNode* root) 
        {
                if(root==NULL)
                        return true;
                stack<TreeNode *>st;
                TreeNode *cur = root;
                TreeNode *pre = NULL;
                while (cur!=NULL||!st.empty())
                {
                        if(cur!=NULL)
                        {
                                st.push(cur);
                                cur=cur->left;
                        }
                        else{
                                cur = st.top();
                                st.pop();
                                if(pre!=NULL&&pre->val>=cur->val)
                                        return false;
                                pre = cur;
                                cur = cur->right;
                        }
                }
                return true;
        }
};
