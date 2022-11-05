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
        TreeNode (int x): val(x),left(NULL),right(NULL){}
        TreeNode (int x, TreeNode *left,TreeNode *right): val(x),left(left),right(right){}
};

//递归法
class Solution {
public:
        bool compare(TreeNode *left,TreeNode *right)
        {
                //确定递归终止条件
                if(left==NULL&&right) return false;
                else if(left&&right==NULL) return false;
                else if (left==NULL&&right==NULL) return true;
                else if(left->val!=right->val) return false;
                //单层递归
                bool isOutside = compare(left->left,right->right);      //外侧：左子树的左节点 与右子树的右节点
                bool isInside = compare(left->right,right->left);       //内侧：左子树的右节点 与右子树的左节点
                bool isSame = isOutside&&isInside;
                return isSame;
        }
        bool isSymmetric(TreeNode* root) {
                if(root==NULL) return true;
                bool res=compare(root->left,root->right);
                return res;
        }
};

//迭代法
class Solution {
public:
        bool isSymmetric(TreeNode* root) {
                if(root==NULL) return true;
                queue<TreeNode *> qu;
                qu.push(root->left);
                qu.push(root->right);
                while (!qu.empty())
                {
                        TreeNode *left = qu.front();
                        qu.pop();
                        TreeNode *right = qu.front();
                        qu.pop();
                        
                        if(left==NULL &&right==NULL) 
                        {
                                continue;
                        }                

                        if(!left&&right) return false;
                        else if(left&&!right) return false;
                        else if(left->val!=right->val) return false;
                        
                        qu.push(left->left);    //左外侧
                        qu.push(right->right);  //右外侧
                        qu.push(left->right);   //左右侧
                        qu.push(right->left);   //右左侧
                }
                         
                return true;
        }
};

//迭代法使用栈
class Solution {
public:
        bool isSymmetric(TreeNode* root) {
                if(root==NULL) return true;
                stack<TreeNode *> st;
                st.push(root->right);
                st.push(root->left);
                while (!st.empty())
                {
                        TreeNode *left = st.top();
                        st.pop();
                        TreeNode *right = st.top();
                        st.pop();
                        
                        if(!left&&!right) continue;
                         if(!left&&right) return false;
                         else if(left&&!right) return false;
                         else if(left->val!=right->val) return false;

                         st.push(right->right);
                         st.push(left->left);
                         st.push(right->left);
                         st.push(left->right);    
                }
                return true;
        }
};