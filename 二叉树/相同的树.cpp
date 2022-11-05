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

//递归法
class Solution {
public:
        bool compare(TreeNode *left,TreeNode *right)
        {
                //终止条件
                if(!left&&right) return false;
                else if(left&&!right)   return false;
                else if(!left&&!right) return true;
                else if(left->val!=right->val) return false;

                //单层递归
                bool isOutside = compare(left->left,right->left);
                bool isInside = compare(left->right,right->right);
                bool isSame = isOutside&&isInside;
                return isSame;
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
                 return compare(p,q);
        }
};

int main()
{
        TreeNode *p = new TreeNode(1);
        TreeNode *q = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);
        
        Solution so;
        cout<<so.compare(p,q)<<endl;
}