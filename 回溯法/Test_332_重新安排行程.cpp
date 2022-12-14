#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include<map>
using namespace std;



class Solution {
public:
        //unordered_map<出发机场,map<到达机场,航班次数>>targets;
        unordered_map<string,map<string,int>>targets;
        bool backtracking(int ticketNum,vector<string>&res)
        {
                //终止条件
                //遇到的机场个数，如果达到了（航班个数+1），那么就找到了一个行程
                if(res.size()==ticketNum+1)
                        return true;
                //单次循环
                for(pair<const string,int>&targets:targets[res[res.size()-1]])
                {
                        if(targets.second>0) //记录到达机场是否飞过了
                        {
                                res.push_back(targets.first);
                                targets.second--;
                                if(backtracking(ticketNum,res))
                                        return true;
                                res.pop_back();
                                targets.second++;
                        }
                }
                return false;
        }
        vector<string> findItinerary(vector<vector<string>>& tickets) {
                targets.clear();
                vector<string>res;
                for(const vector<string>&vec:tickets)
                        targets[vec[0]][vec[1]]++;      //记录映射关系
                res.push_back("JFK");   //起始机场
                backtracking(tickets.size(),res);
                return res;
        }
};

int main(int argc, const char** argv) {
        Solution so;
        vector<vector<string>>tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        vector<string>res;
        res = so.findItinerary(tickets);
        return 0;
}