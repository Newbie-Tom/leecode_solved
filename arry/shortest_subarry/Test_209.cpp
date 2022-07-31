#include <iostream>
#include <vector>
using namespace std;
using std::vector;


// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int result= INT32_MAX;
//         int sum = 0;
//         int start=0;
//         int sublength=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];            
//             while (sum>=target)
//             {
//                 sublength=i-start+1;
//                 result=result<sublength?result:sublength;
//                 sum-=nums[start++];
//             }   
//         }
//         return result ==INT32_MAX?0:result;
//     }
// };

//暴力解法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result= INT32_MAX;
        int sum = 0;
        int sublength=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for (int j = i; j < nums.size(); j++)
            {
                sum+=nums[j];
                if(sum>=target)
                {
                    sublength= j-i+1;
                    result=result<sublength?result:sublength;
                    break;
                }
            }
            
        }
        return result==INT32_MAX?0:result;
    }
};