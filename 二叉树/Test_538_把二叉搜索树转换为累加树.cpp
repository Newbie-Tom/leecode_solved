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
/*
*累加树的定义
*即使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
*二者的关系就是中序遍历二叉搜索树然后从最后一个数字开始往前遍历累加，即可得出结论。
*可以使用中序遍历先访问右节点，再访问左节点即可达到从大到小访问，依次累加即可。
*即反中序遍历法
*/
class Solution {
public:
        int pre = 0;
        void TravelNode(TreeNode *cur)
        {
                //遇到NULL就停止
                if(cur==NULL)
                        return;
                //右中左的遍历顺序
                TravelNode(cur->right);
                cur->val +=pre;
                pre = cur->val;
                TravelNode(cur->left);
        }

        TreeNode* convertBST(TreeNode* root) {
                pre= 0;
                TravelNode(root);
                return root;
        }
};

//迭代
class Solution {
public:
        int pre = 0;
        TreeNode* convertBST(TreeNode* root) {
                pre= 0;
                if(root==NULL) return NULL;
                stack<TreeNode *>st;
                TreeNode *cur  = root;
                while (cur!=NULL||!st.empty())
                {
                        if(cur!=NULL)
                        {
                                st.push(cur);
                                cur  =cur->right;
                        }
                        else
                        {
                                cur = st.top();
                                st.pop();
                                cur->val+=pre;
                                pre = cur->val;
                                cur = cur->left;
                        }
                }
                
                return root;
        }
};