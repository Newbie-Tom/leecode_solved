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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if(root1==NULL)
            return root2;
        if(root2==NULL)
            return root1;

        root1->val+=root2->val;

        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);


        return root1;
    }
};
