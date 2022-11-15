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
        //终止条件
        if(cur==NULL) return ;
        if(result.size()==depth) result.push_back(vector<int> ());
        //添加根节点
        result[depth].push_back(cur->val);
        //左子节点
        order(cur->left,result,depth+1);
        //右子节点
        order(cur->right,result,depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth=0;
        order(root,result,depth);
        return result;
    }
};
