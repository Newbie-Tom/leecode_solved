#include  <iostream>
#include  <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastIndex=0,slowIndex=0;
        //定义快慢指针，起始都指向第1位
        for(int i=fastIndex;i<nums.size();i++)
        {
                if(nums[i]!=val)
                {
                        nums[slowIndex++]=nums[i];
                }
        }
        return slowIndex;
    }
};