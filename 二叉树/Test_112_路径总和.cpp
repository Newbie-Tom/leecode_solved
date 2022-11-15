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

//递归
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        stack<pair<TreeNode*,int>>st;
        st.push(pair<TreeNode*,int>(root,root->val));
        while (!st.empty())
        {
            pair<TreeNode*,int> pr = st.top();
            st.pop();
            if(!pr.first->left&&!pr.first->right&&targetSum==pr.second) return true;
            if(pr.first->right) st.push(pair<TreeNode*,int>(pr.first->right,pr.second+pr.first->right->val));
            if(pr.first->left) st.push(pair<TreeNode*,int>(pr.first->left,pr.second+pr.first->left->val));
            
        }
        return false;
    }
};

int main()
{
    Solution so;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    cout<<so.hasPathSum(root,5)<<endl;
    return 0;

}