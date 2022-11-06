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

//递归中的后序
class Solution {
public:
        int getDepth(TreeNode *node)
        {
                //终止条件
                if(node==NULL) return 0;
                int leftDepth = getDepth(node->left);
                int rightDepth = getDepth(node->right);
                return 1+max(leftDepth,rightDepth);
        }
        int maxDepth(TreeNode* root) 
        {
                if(root==NULL) return 0;
                return getDepth(root);
        }
};

//递归中的前序（中左右）
class Solution {
public:
        int result;
        void getDepth(TreeNode *node,int depth)
        {
                result = result>depth?result:depth;     //计算当前节点的深度
                if(node->left)  //左节点非空
                {
                        depth++;
                        getDepth(node->left,depth);
                        depth--;        //回溯到当前节点
                }
                if(node->right) //右节点非空
                {
                        depth++;
                        getDepth(node->right,depth);
                        depth--;        //回溯到当前节点
                }
        }
        int maxDepth(TreeNode* root) 
        {
                if(root==NULL) return 0;
                result = 0;
                getDepth(root,1);       //根节点的depth为1
                return result;  //返回高度
        }
};

//层序遍历
class Solution {
public:
        
        int maxDepth(TreeNode* root) 
        {
                if(root==NULL) return 0;
                int depth =0;
                queue<TreeNode *> qu;
                qu.push(root);
                while (!qu.empty())
                {
                        int size = qu.size();
                        depth++;        //计算一次尺度则加一次深度
                        for(int i=0;i<size;i++)
                        {
                                TreeNode *cur = qu.front();
                                qu.pop();
                                if(cur->left)   qu.push(cur->left);
                                if(cur->right) qu.push(cur->right);
                        }
                }
                return depth; 
        }
};