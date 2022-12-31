#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static bool cmp(int a,int b)
    {
        return abs(a)>abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum=0;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0&&k>0)
            {
                nums[i]*=-1;
                k--;   
            }
        }
        while (k>0)
        {
            nums[nums.size()-1]*=-1;
            k--;
        }
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return sum;
    }
};