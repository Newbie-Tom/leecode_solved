#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
        vector<int>path;
        vector<vector<int>>res;
        void backtracking(int n,int k,int startIndex)
        {
                //终止条件，即path数组内的数量为k时
                if(path.size()==k)
                {
                        res.push_back(path);
                        return ;
                }
                for (int  i = startIndex; i <=n; i++)
                {
                        path.push_back(i);
                        backtracking(n,k,i+1);
                        //弹出、回溯
                        path.pop_back();
                }
                
        }
        vector<vector<int>> combine(int n, int k) {
                path.clear();
                res.clear();
                backtracking(n,k,1);
                return res;
        }
};


//剪枝优化
class Solution {
public:
        vector<int>path;
        vector<vector<int>>res;
        void backtracking(int n,int k,int startIndex)
        {
                //终止条件，即path数组内的数量为k时
                if(path.size()==k)
                {
                        res.push_back(path);
                        return ;
                }
                // i为本次搜索的起始位置
                for (int  i = startIndex; i <=n-(k-path.size())+1; i++)
                {
                        path.push_back(i);
                        backtracking(n,k,i+1);
                        //弹出、回溯
                        path.pop_back();
                }
        }
        vector<vector<int>> combine(int n, int k) {
                path.clear();
                res.clear();
                backtracking(n,k,1);
                return res;
        }
};