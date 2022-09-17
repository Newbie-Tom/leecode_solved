#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowPointer=0;
        for(int fastPointer=0;fastPointer<nums.size();fastPointer++)
        {
                if(nums[fastPointer]!=nums[slowPointer])
                {
                        nums[++slowPointer]=nums[fastPointer];
                }
        }
        return slowPointer+1;
    }
};

int main()
{
        Solution so;
        vector<int> nums{1,1,2};
        cout<<so.removeDuplicates(nums)<<endl;
        return 0;
}