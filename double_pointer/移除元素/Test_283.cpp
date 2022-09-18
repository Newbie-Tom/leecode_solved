#include <iostream>
#include <vector>
using namespace std;
using std::vector;
#include <algorithm>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowPointer=0;
        for(int fastPointer=0;fastPointer<nums.size();fastPointer++)
        {
                if(nums[fastPointer]!=0)
                {
                        nums[slowPointer++]=nums[fastPointer];
                }
        }
        while(slowPointer<nums.size()) nums[slowPointer++]=0;
    }
};