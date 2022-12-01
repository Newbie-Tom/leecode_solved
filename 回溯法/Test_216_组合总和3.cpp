#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
        vector<int>path;
        vector<vector<int>>res;
        int sum;
        void backtracking(int k,int n,int startIndex)
        {
                if(path.size()==k)
                {
                        if(sum==n)
                                res.push_back(path);
                        return;
                }
                for(int i=startIndex;i<=9;i++)
                {
                        path.push_back(i);
                        sum+=i;
                        backtracking(k,n,i+1);
                        sum-=i;
                        path.pop_back();
                }                
        }
        vector<vector<int>> combinationSum3(int k, int n) {
                path.clear();
                res.clear();
                sum = 0;
                backtracking(k,n,1);
                return res;
        }
};


//剪枝
class Solution {
public:
        vector<int>path;
        vector<vector<int>>res;
        int sum;
        void backtracking(int k,int n,int startIndex)
        {
                if(path.size()==k)
                {
                        if(sum==n)
                                res.push_back(path);
                        return;
                }
                for(int i=startIndex;i<=9-(k-path.size())+1;i++)
                {
                        path.push_back(i);
                        sum+=i;
                        if(sum>n)
                        {
                                sum-=i;
                                path.pop_back();
                                return;
                        }
                        backtracking(k,n,i+1);
                        sum-=i;
                        path.pop_back();
                }                
        }
        vector<vector<int>> combinationSum3(int k, int n) {
                path.clear();
                res.clear();
                sum = 0;
                backtracking(k,n,1);
                return res;
        }
};
