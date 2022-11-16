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



class Solution {
public:
    TreeNode* TravelNode(vector<int>& preorder,vector<int>&inorder)
    {
        //如果前序大小为0,返回空
        if(preorder.size()==0)  return NULL;

        //1.从前序提取根节点,创建二叉树
        int rootValue = preorder[0];
        TreeNode *root = new TreeNode(rootValue);

        //如果前序大小为1,返回跟节点
        if(preorder.size()==1) return root;

        //2.根据根节点找到中序的切割点
        int cutPoint ;
        for(cutPoint=0;cutPoint<inorder.size();cutPoint++)
            if(inorder[cutPoint]==rootValue)
                break;
        
        //3.切割中序
        vector<int> leftinorder(inorder.begin(),inorder.begin()+cutPoint);
        vector<int> rightinorder (inorder.begin()+cutPoint+1,inorder.end());
        
        //4.前序舍弃第一个数
        vector<int>newpreorder(preorder.begin()+1,preorder.end());
        preorder.resize(preorder.size()-1);
        preorder = newpreorder;
        
        //5.分割前序
        vector<int> leftpreorder(preorder.begin(),preorder.begin()+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+leftinorder.size(),preorder.end());
        
        root->left = TravelNode(leftpreorder,leftinorder);
        root->right = TravelNode(rightpreorder,rightinorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)
            return NULL;
        return TravelNode(preorder,inorder);
    }
};



int main()
{
    vector<int>preorder{3,9,20,15,7};
    vector<int>inorder {9,3,15,20,7};
    Solution so;
    TreeNode *root = so.buildTree(preorder,inorder);
    return 0;

}