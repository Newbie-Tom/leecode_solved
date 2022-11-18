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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        TreeNode *cur =NULL;
        if (root->val < val)
            cur= searchBST(root->right, val);
        if (root->val > val)
            cur= searchBST(root->left, val);
        return cur;
    }
};