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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *>qu;
        if(root==NULL)
            return 0;
        int res =0;
        qu.push(root);
        while (!qu.empty())
        {
            int size=qu.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = qu.front();
                qu.pop();
                if (i == 0) res = cur->val;
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }
        }
        return res;   
    }
};

class Solution {
public:
    int res;
    int maxDepth;
    void getLeftVal(TreeNode *cur,int depth)
    {
        if(cur->left==NULL&&cur->right==NULL)
        {
            if(depth>maxDepth)
            {
                maxDepth=depth;            
                res = cur->val;
            }
            return ;
        }    
        if(cur->left)
        {
            depth++;
            getLeftVal(cur->left,depth);
            depth--;
        }
        if(cur->right)
        {
            depth++;
            getLeftVal(cur->right,depth);
            depth--;
        }
        return ;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        res =0;
        maxDepth=INT32_MIN;
        getLeftVal(root,0);
        return res;
    }
};