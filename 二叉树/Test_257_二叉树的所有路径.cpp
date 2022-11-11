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
       TreeNode():val(0),left(NULL),right(NULL){}
       TreeNode(int x):val(x),left(NULL),right(NULL){}
       TreeNode(int x,TreeNode *left,TreeNode *right) :val(x),left(left),right(right) {}
};


class Solution {
public:
    void traversal(TreeNode *cur,vector<int>& path,vector<string>& result)
    {
        path.push_back(cur->val);
        //终止条件
        if(cur->left==NULL&&cur->right==NULL)
        {
            string sPath ;
            for(int i=0;i<path.size()-1;i++)
            {
                sPath +=to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            result.push_back(sPath);
            return ;
        }

        if(cur->left){
            traversal(cur->left,path,result);
            path.pop_back();   
        }
            
        if(cur->right){
            traversal(cur->right,path,result);
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> path; vector<string>result;
        traversal(root,path,result);
        return result;
    }
};


