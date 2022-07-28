#include <iostream>
#include <vector>
using namespace std;
using std::vector;

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.empty())
//             return {-1,-1};
//         int left=0; //定义left的索引
//         int right = nums.size()-1;  //左闭右开模式 [left,right] 定义right的索引        
//         int first_target=0,second_target=nums.size()-1;
//         while(left<=right)
//         {
//             int middle = left + ((right-left)/2); //定义middle的索引
//             if(nums[left]==target)      //开头若等于目标值
//             {
//                 first_target = left;
//             }
//             if(nums[right]==target)    //结尾若等于目标值
//             {
//                 second_target = right;
//             } 

//             if(nums[middle]<target)         //右区间
//             {
//                 left = middle + 1;
//             }
//             else if(nums[middle]>target)    //左区间
//             {
//                 right = middle-1;
//             }
//             else    //等于中间值
//             {
//                 if(nums[first_target]!=target)
//                 {
//                     first_target = middle;
//                 }
//                 if(nums[second_target]!=target)
//                 {
//                     second_target = middle;
//                 }
                
                
//                 if(first_target<=second_target)
//                     return {first_target,second_target};
//             }
                
//         }
//         return {-1,-1};
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1,-1};
        //第一次查找
        int firstPosition = findfirstposition(nums,target);
        if(firstPosition==-1)   //第一次查找没有找到
        {
            return {-1,-1};
        }
        //第二次查找
        int lastPosition = findlastposition(nums,target);    
        return {firstPosition,lastPosition};
    }
    private:
        int findfirstposition(vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size()-1;
            while (left<right)
            {
                int middle = (left+right)/2;
                if(nums[middle]>target) //进入 [left,middle-1]
                    right = middle-1;
                else if(nums[middle]==target)    //进入[left,middle]
                    right = middle;
                else            //[middle+1,right]
                    left = middle+1;
            }
            
            if(nums[left]==target)
                return left;
            else
                return -1;
            
        }
        int findlastposition(vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size()-1;
            while (left<right)
            {
                int middle = (left+right+1)/2;
                if(nums[middle]<target) //进入 [middle+1,right]
                    left = middle+1;
                else if(nums[middle]==target)    //进入[middle,right]
                    left = middle;
                else            //[left,middle-1]
                    right = middle-1;
            }
            if(nums[left]==target)
                return left;
            else
                return -1;

        }
};

class Solution;
int main()
{
    Solution so;
    vector<int> v1(2);
    vector<int> nums{5,7,7,8,8,10};
    int target = 6;
    v1 = so.searchRange(nums,target);
    for(int i = 0;i<v1.size();i++)
        cout<<v1[i]<<endl;
    return 0;
}