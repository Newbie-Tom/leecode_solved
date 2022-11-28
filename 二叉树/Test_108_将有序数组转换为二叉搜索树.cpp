#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include<unordered_map>
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
        TreeNode *TravelNode(vector<int>&nums,int left,int right)
        {
                if(left>right)
                        return NULL;
                int mid  = left + (right-left)/2;
                TreeNode *root =  new TreeNode(nums[mid]);
                root->left = TravelNode(nums,left,mid-1);
                root->right = TravelNode(nums,mid+1,right);
                return root;

        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
                return TravelNode(nums,0,nums.size()-1);
        }
};

//迭代
class Solution {
public:
        
        TreeNode* sortedArrayToBST(vector<int>& nums) {
                if(nums.size()==0) return NULL;

                TreeNode *root = new TreeNode(0);
                queue<TreeNode *> Nodeque;
                queue<int> leftque;
                queue<int> rightque;
                
                Nodeque.push(root);
                leftque.push(0);
                rightque.push(nums.size()-1);

                while (!Nodeque.empty())
                {
                        TreeNode *cur = Nodeque.front();
                        Nodeque.pop();

                        int left = leftque.front(); leftque.pop();
                        int right = rightque.front(); rightque.pop();
                        int mid  = left + (right-left)/2;
                       
                        cur->val = nums[mid];

                         if (left<=mid-1)
                        {
                                cur->left = new TreeNode(0);
                                Nodeque.push(cur->left);
                                leftque.push(left);
                                rightque.push(mid-1);
                        }
                        if (right>=mid+1)
                        {
                                cur->right = new TreeNode(0);
                                Nodeque.push(cur->right);
                                leftque.push(mid+1);
                                rightque.push(right);
                        }
                }
                return root;
        }
};