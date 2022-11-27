#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//迭代

class Solution {
public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
                if(root==NULL)
                {
                        TreeNode *node = new TreeNode(val);
                        return node;
                }
                TreeNode *cur = root;

                while (cur)
                {
                        if(cur->val<val){
                                if(cur->right)
                                        cur = cur->right;
                                else
                                {
                                        TreeNode *node = new TreeNode(val);
                                        cur->right = node;
                                        break;
                                }
                        }                
                        else if(cur->val>=val){
                                if(cur->left)
                                      cur=cur->left;  
                                else
                                {
                                        TreeNode *node = new TreeNode(val);
                                        cur->left = node; 
                                        break;       
                                }
                        }
                }
                return root;
        }
};


//递归
class Solution {
public:

        TreeNode* insertIntoBST(TreeNode* root, int val) {
                if(root==NULL)
                {
                        TreeNode *node = new TreeNode(val);
                        return node;
                }
                
                if(root->val>val) root->left = insertIntoBST(root->left,val);
                if(root->val<val) root->right = insertIntoBST(root->right,val);

                return root;
        }
};
//递归无返回值
class Solution {
public:
        TreeNode *parent;
        void TravelNode(TreeNode *cur,int val)
        {
                if(cur==NULL)
                {
                        TreeNode *node = new TreeNode(val);
                        if(parent->val<val)
                                parent->right = node;
                        else parent->left = node;
                        return ;
                }
                parent = cur;
                if(cur->val>val) TravelNode(cur->left,val);
                if(cur->val<val) TravelNode(cur->right,val);
        }
        TreeNode* insertIntoBST(TreeNode* root, int val) {
                parent = new TreeNode(0);
                if(root==NULL)
                {
                        root = new TreeNode(val);                        
                }
                TravelNode(root,val);
                return root;
        }
};