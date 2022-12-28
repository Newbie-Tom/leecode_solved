#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) 
            return nums.size();
        int curDiff=0;
        int preDiff=0;
        int res=1;  //记录峰值个数,默认最右边有一个峰值
        for(int i=0;i<nums.size()-1;i++)
        {
            curDiff = nums[i+1]-nums[i];
            if((curDiff>0&&preDiff<=0)||(preDiff>=0&&curDiff<0))
            {
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
};