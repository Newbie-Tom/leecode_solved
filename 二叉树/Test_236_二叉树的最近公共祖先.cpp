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


class Solution {
public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                //终止条件
                if(root==q||root==p||root==NULL) return root;
                //递归,带返回值
                TreeNode *left = lowestCommonAncestor(root->left,p,q);
                TreeNode *right = lowestCommonAncestor(root->right,p,q);

                if(left!=NULL&&right!=NULL) return root;        //左右返回值都不为空，则返回root
                //处理左右返回值
                if(left==NULL&&right!=NULL) return right;
                else if(left!=NULL&&right==NULL) return left;
                else return NULL;

        }
};