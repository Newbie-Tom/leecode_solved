#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // if(nums.size()==1&&nums[0]==0)
        //     break;
        int slowpointer =0;
        int fastpointer=0;
        while (fastpointer<nums.size())
        {
            if(nums[fastpointer]!=0)
            {
                nums[slowpointer++] = nums[fastpointer];
            }
            fastpointer++;
        }
        while(slowpointer<fastpointer)
        {
            nums[slowpointer++]=0;
        }
    }
};
int main()
{
    Solution so;
    
    vector<int> nums{0};
    so.moveZeroes(nums);
    for(int i = 0;i<nums.size();i++)
        cout<<nums[i]<<endl;
    return 0;
}