#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right){} 
};

//前序
class Solution {
public:
    void TravelNode(TreeNode *cur,vector<int> &result)
    {
        if(cur==NULL)  return; //终止条件
        result.push_back(cur->val); //根
        TravelNode(cur->left,result);  //左
        TravelNode(cur->right,result);  //右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TravelNode(root,result);
        return result;
    }
};

class Solution {
public:
    void TravelNode(TreeNode *cur,vector<int> &result)
    {
        if(cur==NULL)  return; //终止条件
        TravelNode(cur->left,result);  //左
        result.push_back(cur->val); //根
        TravelNode(cur->right,result);  //右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TravelNode(root,result);
        return result; 
    }
};

class Solution {
public:
    void TravelNode(TreeNode *cur,vector<int> &result)
    {
        if(cur==NULL)  return; //终止条件
        TravelNode(cur->left,result);  //左
        TravelNode(cur->right,result);  //右
        result.push_back(cur->val); //根
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TravelNode(root,result);
        return result; 
    }
};

