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
        void  TravelNode(TreeNode*cur,unordered_map<int,int>&map)
        {
                if(cur==NULL)
                        return ;
                map[cur->val]++;
                TravelNode(cur->left,map);
                TravelNode(cur->right,map);
        }
        bool static cmp(const pair<int,int>&a,const pair<int,int>&b)
        {
                return a.second>b.second;
        }
        vector<int> findMode(TreeNode* root) {
                if(root==NULL)
                        return {};
                unordered_map<int,int>map;
                vector<int>res;
                TravelNode(root,map);
                vector<pair<int,int>>vec(map.begin(),map.end());
                sort(vec.begin(),vec.end(),cmp);
                res.push_back(vec[0].first);
                for(int i=1;i<map.size();i++)
                {
                        if(vec[i].second==vec[0].second)
                                res.push_back(vec[i].first);
                        else
                                break;
                }
                return res;

        }
};

int main(int argc, const char** argv) {
        Solution so;
        TreeNode *root = new TreeNode(1);
        root->right=new TreeNode(2);
        root->right->left = new TreeNode(2);
        vector<int>res;
        res=so.findMode(root);
        for(int i=0;i<res.size();i++)
                cout<<res[i]<<endl;
        return 0;
}

