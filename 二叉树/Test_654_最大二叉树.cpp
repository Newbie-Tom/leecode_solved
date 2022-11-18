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

// class Solution {
// public:

//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         //终止条件
//         TreeNode *node = new TreeNode(0);
//         if(nums.size()==1)
//         {
//             node->val = nums[0];
//             return node;      
//         }   

//         //确定单层递归的逻辑
//         int maxValue=0;
//         int maxValueIndex=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(maxValue<nums[i])
//             {
//                 maxValue = nums[i];
//                 maxValueIndex = i;
//             }
//         }
        
//         node->val = maxValue;
//         //确定左子树递归
//         if(maxValueIndex>0)
//         {
//             vector<int>leftNums(nums.begin(),nums.begin()+maxValueIndex);
//             node->left = constructMaximumBinaryTree(leftNums);
//         }
//         //确定右子树递归
//         if(maxValueIndex<(nums.size()-1))
//         {
//             vector<int>rightNums(nums.begin()+maxValueIndex+1,nums.end());
//             node->right = constructMaximumBinaryTree(rightNums);
//         }

//         return node;
//     }
// };

class Solution {
public:
    TreeNode* TravelNode(vector<int>&nums,int left,int right)
    {

        if(left>=right)
            return NULL;
        
        int maxValueIndex = left;
        for(int i=left;i<right;i++)
        {
            if(nums[maxValueIndex]<nums[i])
                maxValueIndex = i;
        }

        TreeNode *Node = new TreeNode(nums[maxValueIndex]);


        Node->left = TravelNode(nums,left,left+maxValueIndex);

        Node->right = TravelNode(nums,left+maxValueIndex+1,right);

        return Node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //终止条件
        return TravelNode(nums,0,nums.size());
    }
};


int main()
{
    Solution so;
    vector<int>nums{3,2,1,6,0,5};
    TreeNode *root=so.constructMaximumBinaryTree(nums);
    return 0;
}