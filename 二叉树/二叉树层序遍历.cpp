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
    TreeNode(int x): val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right) {}
};

//迭代法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;
        queue<TreeNode *>qu;
        if(root==NULL) return result;
        qu.push(root);
        while (!qu.empty())
        {
            int size = qu.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = qu.front();
                temp.push_back(cur->val);
                qu.pop();
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }
         result.push_back(temp);
         temp.clear();   
        }
        return result;   
    }
};

//递归法
class Solution {
public:
    void order(TreeNode *cur,vector<vector<int>> &result,int depth)
    {
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        
    }
};
