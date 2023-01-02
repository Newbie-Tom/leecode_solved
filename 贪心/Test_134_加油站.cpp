#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//暴力方式
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<cost.size();i++)
        {
            int rest = gas[i]-cost[i];  //记录剩余油量
            int index = (i+1)%cost.size();  //记录前往下一站的索引    
            while (rest>0&&index!=i)    //以index为起点行驶一圈
            {
                rest+=gas[index] - cost[index];
                index = (index+1)%cost.size();
            }
            //如果以i为起点跑一圈,剩余油量>=0,返回起点位置
            if(rest>=0&&index==i)
                return i;
        }
        return -1;
        
    }
};

//贪心1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT32_MAX;    //从起点出发,此时邮箱里油量的最小值
        for(int i=0;i<gas.size();i++)
        {
            int rest = gas[i]-cost[i];
            curSum+=rest;   //curSum用于累加gas和cost的总和差
            if(curSum<min)
                min = curSum;    
        }
        //情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
        if(curSum<0) 
            return -1;
        //情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。
        if(min>=0)
            return 0;
        //情况三:情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能这个负数填平，能把这个负数填平的节点就是出发节点。
        for(int j=gas.size()-1;j>=0;j--)
        {
            int rest = gas[j]-cost[j];
            min+=rest;
            if(min>=0)
                return j;
        }
        return -1;        
        
    }
};

//贪心2
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum=0;
        int start = 0;
        for(int i=0;i<gas.size();i++)
        {
            curSum+=gas[i]-cost[i];     //局部差
            totalSum+=gas[i]-cost[i];   //全局差
            if(curSum<0)    //如果局部差<0,则起始位置需要往后移一位,且局部清零
            {
                curSum=0;
                start = i+1;
            }
        }
        if(totalSum<0)
            return -1;
        return start;
        
    }
};