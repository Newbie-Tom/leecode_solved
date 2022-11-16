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
    TreeNode* TravelNode(vector<int>&inorder,vector<int>& postorder)
    {
        //1.如果数组大小为0,则为空节点
        if(postorder.size()==0) return NULL;

        //2.如果不为空,取后序数组最后一个元素作为节点元素
        int rootValue = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(rootValue);

        //叶子节点
        if(postorder.size()==1) return root;

        //3.找到后序数组最后一个元素在中序数组的位置,作为切割点
        int delimiterIndex;
        for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++)
            if(inorder[delimiterIndex]==rootValue)
                break;

        //4.切割中序数组，切成中序左数组和中序右数组 
        vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiterIndex);
        vector<int> rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());

        //舍弃后序的最后一个数
        postorder.resize(postorder.size()-1);

        //5.切割后序数组，切成后序左数组和后序右数组
        vector<int> leftPoster(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPoster(postorder.begin()+leftInorder.size(),postorder.end());

        root->left= TravelNode(leftInorder,leftPoster);
        root->right = TravelNode(rightInorder,rightPoster);
        return root;        
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0)
            return NULL;
        return TravelNode(inorder,postorder);
    }
};