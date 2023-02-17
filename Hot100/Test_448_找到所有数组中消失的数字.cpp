#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// class Solution {
// public:
//         vector<int> findDisappearedNumbers(vector<int>& nums) {
//                 vector<int>temp(nums.size(),1);
//                 vector<int>res;
//                 for(int i=0;i<nums.size();i++)
//                 {
//                         temp[nums[i]-1]--;
//                 }
//                 for(int i=0;i<temp.size();i++)
//                 {
//                         if(temp[i]==1)
//                                 res.push_back(i+1);
//                 }
//                 return res;
//         }
// };

//原地修改
class Solution {
public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
                int n = nums.size();
                vector<int>res;
                for(int i=0;i<nums.size();i++)
                {
                        int x = (nums[i]-1)%n;
                        nums[x]+=n;
                }
                for(int i=0;i<nums.size();i++)
                {
                        if(nums[i]<=n)
                               res.push_back(i+1); 
                }
                return res;
        }
};

int main()
{
        vector<int>nums = {4,3,2,7,8,2,3,1};
        vector<int>res;
        Solution so;    
        res = so.findDisappearedNumbers(nums);
}


