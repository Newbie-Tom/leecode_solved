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
        int getHeight(TreeNode *Node)
        {
                if(Node==NULL) return 0;

                int leftHeight = getHeight(Node->left);
                if(leftHeight==-1)  return -1;
                int rightHeight = getHeight(Node->right);
                if(rightHeight==-1) return -1;

                return abs(leftHeight-rightHeight)<=1?1+max(leftHeight,rightHeight):-1;

        }
        bool isBalanced(TreeNode* root) {
                return getHeight(root)==-1?false:true;
        }
};

class Solution {
public:
        int getDepth(TreeNode *cur)
        {
            stack<TreeNode *>st;
            if(cur!=NULL) st.push(cur);
            int depth = 0;
            int result = 0;
            while (!st.empty())
            {
                TreeNode *node = st.top();
                if(node!=NULL)
                {
                    st.pop();
                    st.push(node);
                    st.push(NULL);
                    depth++;
                    if(node->left) st.push(node->left);
                    if(node->right) st.push(node->right);
                }
                else
                {
                    st.pop();
                    node = st.top();
                    st.pop();
                    depth--;
                }
                result = result>depth?result:depth;
            }
            return result;
            
        }
        bool isBalanced(TreeNode* root) {
            stack<TreeNode *>st;
            if(root==NULL) return true;
            st.push(root);
            while (!st.empty())
            {
                TreeNode *node = st.top();
                st.pop();
                if(abs(getDepth(node->left)-getDepth(node->right))>1)
                {
                    return false;
                }
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
            return true;
        }
};