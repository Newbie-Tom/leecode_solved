#include <iostream>
#include <vector>
using namespace std;
using std::vector;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       /*第一步找到中间值并求其平均值*/
       int mid = findmidposition(nums);
       vector<int> NUMS(nums.size());
       /*三种情况:1.单调增 2.单调减 3.抛物线*/
       if(mid==0)
            return nums;
       else if(mid==nums.size()-1)
            {
                int i=0;
                while (mid>=0)
                {
                    NUMS[i++] = nums[mid--];
                }
                return NUMS;
            }
        else
        {
            int left = mid-1;
            int right = mid+1;
            NUMS[0]=nums[mid];
            int i= 1;
            while(left>=0&&right<=nums.size()-1)
            {
                if(nums[left]<nums[right])
                {
                    NUMS[i++]=nums[left];
                   
                    left--;
                }
                else
                {
                    NUMS[i++]=nums[right];
                    right++;
                }
            }
            int length = NUMS.size()-1;
            int j=0;
            while (left>=0)
            {
                NUMS[length]=nums[j];
                length--;
                left--;
                j++;
            }
            while (right<=nums.size()-1)
            {
                NUMS[i++]=nums[right++];  
            }   
            return NUMS;
        }       
    }
private:
    int findmidposition(vector<int>& nums)
    {   
        int mid = 0;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]*=nums[i];   //求平方
            if(nums[i]<nums[mid])
            {
                mid =i;    
            }   
        }
        return mid;   
    }
};


int main()
{
    vector<int> nums{-4,-1,0,3,10};
    vector<int> NUMS(nums.size());
    Solution so;
    NUMS = so.sortedSquares(nums);
    for(int i=0;i<NUMS.size();i++)
    {
        cout<<NUMS[i]<<endl;
    }

    return 0;
}


