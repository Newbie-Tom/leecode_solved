#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
        int maxDepth(Node* root) {
                if(root==NULL) return 0;
                queue<Node *>qu;
                int depth=0;
                qu.push(root);
                while (!qu.empty())
                {
                        int size = qu.size();
                        depth++;
                        for(int i=0;i<size;i++)
                        {
                                Node *cur = qu.front();
                                qu.pop();
                                for(int i=0;i<cur->children.size();i++)
                                {
                                        if(cur->children[i]) qu.push(cur->children[i]);
                                }
                                
                        }
                }
                return depth;
        }
};
