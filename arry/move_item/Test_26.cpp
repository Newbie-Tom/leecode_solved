#include <iostream>
#include <vector>
using namespace std;
using std::vector;


//快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowpointer = 0;    //慢指针
        for(int fastpointer =1;fastpointer<nums.size();fastpointer++)   //快指针比慢指针初始值快一步
        {
            if(nums[fastpointer]!=nums[slowpointer])
            {
                nums[++slowpointer] = nums[fastpointer];   
            }

        }
        return slowpointer+1;
    }
};

// //暴力法
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int low = 0;
//         int key = 1;
//         int j=1;
//         for(int fast=1;fast<nums.size();fast++)
//         {
//             if(nums[fast]==nums[low])
//             {
//                 for(;j<nums.size();j++)
//                 {
                    
//                     nums[j]=nums[++key];
//                 }
//                 low++;
//                 j=low;

//             }   
//         }
//         return low;
//     }
// };

int main()
{
    Solution so;
    
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int returnval = -1;
    returnval = so.removeDuplicates(nums);
    cout<<returnval<<endl;
    for(int i = 0;i<returnval;i++)
        cout<<nums[i]<<endl;
    return 0;
}