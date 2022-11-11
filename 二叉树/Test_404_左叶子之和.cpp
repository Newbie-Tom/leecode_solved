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
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL&&root->right==NULL)
            return 0;
        int leftVal = sumOfLeftLeaves(root->left);
        if(root->left&&root->left->left==NULL&&root->left->right==NULL)
            leftVal = root->left->val;
        int rightVal = sumOfLeftLeaves(root->right);

        return leftVal+rightVal;
    }
};