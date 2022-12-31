#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1)
            return 0;
        int curDistance = 0;    //当前覆盖最远距离下标
        int step = 0;           //记录走的最大步数
        int nextDistance = 0;   //下次覆盖最远距离下标
        for(int i=0;i<nums.size();i++)
        {
            nextDistance = max(i+nums[i],nextDistance);  //更新下一步覆盖范围最远距离下标
            if(i==curDistance)  //遇到当前覆盖最远距离最远下标
            {
                if(curDistance<nums.size()-1)   // 如果当前覆盖最远距离下标不是终点
                {
                    step++;                     // 需要走下一步
                    curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
                    if(nextDistance>=nums.size()-1)     // 下一步的覆盖范围已经可以达到终点，结束循环
                        break;
                }
                else
                    break;                      // 当前覆盖最远距离下标是集合终点，不用做ans++操作了，直接结
            }
        }
        return step;
    }
};