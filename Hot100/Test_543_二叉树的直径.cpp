#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL) {}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};


class Solution {
    private:
    int ans = 0;
    int heightOfBinaryTree(TreeNode *node)
    {
        if(!node)
            return 0;
        int Left = heightOfBinaryTree(node->left);
        int right = heightOfBinaryTree(node->right);
        ans = max(ans,Left+right+1);
        return max(Left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;
        heightOfBinaryTree(root);
        return ans-1;
    }
};