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

//迭代
class Solution {
public:
        TreeNode *deleteOneNode(TreeNode *target)
        {
                if(target==NULL) return target;
                if(target->right==NULL) return target->left;
                TreeNode *cur = target->right;
                while (cur->left)
                {
                        cur = cur->left;
                }
                cur->left = target->left;
                return target->right;
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
                if(root==NULL) return root;
                TreeNode *cur = root;
                TreeNode *pre = NULL;
                while (cur)
                {
                        if(cur->val ==key)
                                break;
                        pre = cur;
                        if(cur->val>key)
                                cur = cur->left;
                        else
                                cur = cur->right;                        
                }       
                if(pre==NULL)
                        return deleteOneNode(cur);
                if(pre->left&&pre->left->val==key)       // pre 要知道是删左孩子还是右孩子
                        pre->left = deleteOneNode(cur);
                if(pre->right&&pre->right->val==key)
                        pre->right = deleteOneNode(cur);
                return root;
        }
};

//递归

class Solution {
public:
        TreeNode* deleteNode(TreeNode* root, int key) {
               // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
                if(root==NULL) return root;     
                // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
                if(root->val==key){
                        if(root->left==NULL&&root->right==NULL)
                        {
                                delete root;
                                return NULL;
                        }
                        // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
                        else if(root->left==NULL)
                        {
                                TreeNode temp  = root->right;
                                delete root;
                                return temp;
                        }
                        
                }
                
                return root;
        }
};