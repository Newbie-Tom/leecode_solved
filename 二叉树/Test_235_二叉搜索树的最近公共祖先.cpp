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
        TreeNode *TravelNode(TreeNode *cur,TreeNode *p,TreeNode *q)
        {
                //终止条件
                if(cur==NULL)
                        return cur;
                //单层递归的逻辑（注意二叉搜索树的特性，p->val <= cur->val <= q<val）
                if(cur->val>p->val &&cur->val>q->val)
                {
                        TreeNode *left = TravelNode(cur->left,p,q);
                        if(left!=NULL)
                                return left;
                }

                if(cur->val<p->val &&cur->val<q->val)
                {
                        TreeNode *right = TravelNode(cur->right,p,q);
                        if(right!=NULL)
                                return right;
                }
                        return cur;
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
                return TravelNode(root,p,q);
        }
};

//迭代
class Solution {
public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
                TreeNode *cur = root;
                while (cur)
                {
                        if(p->val<cur->val&&q->val<cur->val)
                                cur = cur->left;
                        else if(p->val>cur->val&&q->val>cur->val)
                                cur = cur->right;
                        else
                                return cur;
                }
                return NULL;
        }
};
