#include <iostream>
#include <vector>
using namespace std;
using std::vector;

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
        
//         int slowpointer = 0;
//         for(int fastpointer = 0;fastpointer<nums.size();fastpointer++)
//         {
//             if(nums[fastpointer]!=val)  //如果快指针指向的数值不等于val
//                 {
//                     nums[slowpointer++] = nums[fastpointer];
//                 }
//         }
//         return slowpointer;
//     }
// };
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //双对向指针
        int leftpointer = 0;
        int rightpointer = nums.size()-1;
        while (leftpointer<=rightpointer)
        {
            //当头<=尾且头指针此时数值不等于val
            while (leftpointer<=rightpointer&&nums[leftpointer]!=val)
            {
                ++leftpointer;
            }
            while (leftpointer<=rightpointer&&nums[rightpointer]==val)
            {
                --rightpointer;
            }
            if(leftpointer<rightpointer)
            {
                nums[leftpointer++]=nums[rightpointer--];
            }
        }
        return leftpointer;
        
    }
};

int main()
{
    Solution so;
    
    vector<int> nums{3,2,2,3};
    int val = 3;
    int returnval = -1;
    returnval = so.removeElement(nums,val);
    cout<<returnval<<endl;
    for(int i = 0;i<returnval;i++)
        cout<<nums[i]<<endl;
    return 0;
}