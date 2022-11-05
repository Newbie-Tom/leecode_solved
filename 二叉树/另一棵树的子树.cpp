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
        TreeNode(int x): val(x),left(NULL),right(NULL) {}
        TreeNode(int x,TreeNode *left,TreeNode *right) :val(x),left(left),right(right){}
};

class Solution {
public:
        bool compare(TreeNode *left,TreeNode *right)
        {
                //终止条件
                
                if(!left&&!right) return true;
                else if(!left||!right) return false;
                else if(left->val!=right->val) return false;

                //单层递归
                bool isOutside = compare(left->left,right->left);
                bool isInside = compare(left->right,right->right);
                return isOutside&&isInside;
               
        }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
                if(!subRoot) return true;       // sub为 null 一定都是 true
                if(!root) return false;              // 这里 sub 一定不为 null, 只要 root为 null，肯定是 false       
                return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot)||compare(root,subRoot);
        }
};

int main()
{
        Solution so;
        TreeNode *p = new TreeNode(1);
        p->right= new TreeNode(1);
        p->right->right = new TreeNode(1);
        p->right->right->right = new TreeNode(1);
        p->right->right->right->right = new TreeNode(1);
        p->right->right->right->right->right = new TreeNode(1);
        p->right->right->right->right->right ->right = new TreeNode(1);
        p->right->right->right->right->right ->right->right = new TreeNode(1);
        p->right->right->right->right->right ->right->right ->right= new TreeNode(1);
        p->right->right->right->right->right ->right->right ->right->right= new TreeNode(1);
        p->right->right->right->right->right ->right->right ->right->right->right= new TreeNode(1);
        p->right->right->right->right->right ->right->right ->right->right->right->left= new TreeNode(2);
        TreeNode *q = new TreeNode(1);
        q->right= new TreeNode(1);
        q->right->right = new TreeNode(1);
        q->right->right->right = new TreeNode(1);
        q->right->right->right->right = new TreeNode(1);
        q->right->right->right->right->right = new TreeNode(1);
        q->right->right->right->right->right ->left= new TreeNode(2);
        cout<<so.isSubtree(p,q);
        return 0;
}