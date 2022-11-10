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
       TreeNode(int x,TreeNode *left,TreeNode *right) :val(x),left(left),right(right) {}
};

//递归
class Solution {
public:
        int getNodeNum(TreeNode *root)
        {
                //终止条件
                if(root==NULL) return 0;

                int leftNum=getNodeNum(root->left);
                int rightNum = getNodeNum(root->right);
                return 1+leftNum+rightNum;
        }        
        int countNodes(TreeNode* root) {
                return getNodeNum(root);
        }
};


//层序遍历
class Solution {
public:
       
        int countNodes(TreeNode* root) {
                if(root==NULL) return 0;
                queue<TreeNode *>qu;
                qu.push(root);
                int result=0;
                while (!qu.empty())
                {
                        
                        int size = qu.size();
                        for(int i=0;i<size;i++)
                        {
                                TreeNode *cur = qu.front();
                                qu.pop();
                                result++;
                                if(cur->left) qu.push(cur->left);
                                if(cur->right) qu.push(cur->right);
                        }
                }
                return result;           
        }
};

class Solution {
public:

        int countNodes(TreeNode* root) {

                if(root==NULL) return 0;
                TreeNode *left = root->left;
                TreeNode *right = root->right;
                
                int leftDepth= 0,rightDepth=0;
                while (left)
                {
                        left = left->left;
                        leftDepth++;
                }
                while (right)
                {
                        right = right->right;
                        rightDepth++;
                }
                if( leftDepth==rightDepth)
                        return (2<< leftDepth)-1;

                
                return countNodes(root->left)+countNodes(root->right)+1;
        }
};

