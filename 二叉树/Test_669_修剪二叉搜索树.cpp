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

        TreeNode* trimBST(TreeNode* root, int low, int high) {
                if(root==NULL) return NULL;
                //处理头节点，让root移动到[L,R]范围内，注意是左闭右闭
                while (root!=NULL&&(root->val<low||root->val>high))
                {
                        if(root->val<low)
                                root = root->right;
                        else
                                root = root->left;                      
                }
                TreeNode *cur = root;
                // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
                while (cur!=NULL)
                {
                        while (cur->left&&cur->left->val<low)
                        {
                                cur->left = cur->left->right;
                        }
                        cur = cur->left;
                }
                cur = root;
                // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
                while (cur!=NULL)
                {
                        while (cur->right&&cur->right->val>high)
                        {
                               cur->right = cur->right->left;
                        }
                        cur = cur->right;
                }
                return root;
        }
};