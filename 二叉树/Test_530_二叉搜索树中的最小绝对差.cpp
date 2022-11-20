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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

        void TravelNode(TreeNode*cur ,vector<int>&res)
        {
                if(cur==NULL)
                        return ;
                TravelNode(cur->left,res);
                res.push_back(cur->val);
                TravelNode(cur->right,res);
        }
        int getMinimumDifference(TreeNode* root) {
                vector<int>res;
                TravelNode(root,res);
                int minVal=INT32_MAX;
                for (int i = 1; i <res.size(); i++)
                {
                        if(abs(res[i]-res[i-1])<minVal) 
                                minVal = abs(res[i]-res[i-1]);
                }
                return minVal;
        }
};

//递归2
class Solution {
public:
        TreeNode *pre=NULL;
        int minVal=INT32_MAX;
        void TravelNode(TreeNode *cur)
        {
                if(cur==NULL)
                        return ;
                TravelNode(cur->left);
                if(pre!=NULL)
                {
                        minVal = min(minVal,cur->val-pre->val);
                }
                pre = cur;
                TravelNode(cur->right);
        }
        int getMinimumDifference(TreeNode* root) {
                
                
                

                return minVal;
        }
};