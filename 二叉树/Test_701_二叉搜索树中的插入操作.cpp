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

//迭代

class Solution {
public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
                while (root)
                {
                        if(root->val<val){
                                if(root->right)
                                        root = root->right;
                                else
                                {
                                        TreeNode *node = new TreeNode(val);
                                        root->right = node;
                                }
                        }                
                        else if(root->val>=val){
                                if(root->left)
                                      root =root->left;  
                                else
                                {
                                        TreeNode *node = new TreeNode(val);
                                        root->left = node;        
                                }
                        }
                }
                return root;
        }
};


int main()
{
        Solution so;
        TreeNode *root  = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        int val = 5;
        so.insertIntoBST(root,5);

        return 0;

}