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
        TreeNode(int x):val(x),left(NULL),right(NULL){}
        TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right){}
};
//递归
class Solution {
public:
        int getDepth(TreeNode *node)
        {
                if(node==NULL) return 0;
                int leftDepth = getDepth(node->left);
                int rightDepth = getDepth(node->right);

                if(node->left==NULL&&node->right)       //如果  左子树为空，右子树不为空
                        return 1+rightDepth;
                
                if(node->left&&node->right==NULL)       //如果  左子树不为空，右子树为空
                        return 1+leftDepth;

                return 1+min(leftDepth,rightDepth);     //如果左右子树都不为空，则返回较小的一边高度+1
        }
        int minDepth(TreeNode* root) {
                return getDepth(root);
        }
};


//层序
class Solution {
public:
        int result;
        void getDepth(TreeNode *node,int depth)
        {
                if(!node->left&&!node->right)   //如果左右子树都为空，则返回深度
                {
                        result  = min(result,depth);
                        return ;
                }
                if(node->left) getDepth(node->left,depth+1);

                if(node->right) getDepth(node->right,depth+1);
                
        }
        int minDepth(TreeNode* root) {
                if(root==NULL) return 0;
                result =INT32_MAX;
                getDepth(root,1);       //根节点的高度为1
                return result;
        }
};


//层序
class Solution {
public:
        int minDepth(TreeNode* root) {
                if(root==NULL) return 0;
                queue<TreeNode *> qu;
                qu.push(root);
                int depth=0;
                while (!qu.empty())
                {
                        int size = qu.size();
                        depth++;
                        for(int i=0;i<size;i++)
                        {
                                TreeNode *cur = qu.front();
                                qu.pop();
                                if(cur->left) qu.push(cur->left);
                                if(cur->right) qu.push(cur->right);
                                if(!cur->left&&!cur->right) return depth;
                        }
                }
                return depth;
        }
};
