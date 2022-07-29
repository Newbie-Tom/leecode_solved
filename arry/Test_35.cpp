#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return 0;   //如果数组为空,则返回索引0
        }
        // int index=-1;   //初始化索引值为-1
        int left=0;     //左端初始值
        int right=nums.size()-1;    //右端初始值
        while (left<=right)
        {
            int mid = (left+right)/2;   //中间值
            if(nums[mid]>target)    //[left,mid-1]
            {
                right = mid -1;
            }
            else if(nums[mid]<target)   //[mid+1,right]
            {
                left = mid+1;
            }
            else
            {
                return mid; //恰好nums[mid]=target,返回mid作为索引
            }                        
        }
        return left;
    }
};
int main()
{

    Solution so;
    int index =-1;
    vector<int> nums;
    int target = 7;
    index= so.searchInsert(nums,target);
    cout<<index<<endl;
    return 0;
}
