#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using std::vector;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int leftPointer=0,rightPointer=nums.size()-1;
        int resPointer=res.size()-1;

        while (leftPointer<rightPointer)
        {
                if(nums[leftPointer]*nums[leftPointer]>=nums[rightPointer]*nums[rightPointer])
                {
                        res[resPointer--]=nums[leftPointer]*nums[leftPointer];
                        leftPointer++;
                }        
                else
                {
                        res[resPointer--]=nums[rightPointer]*nums[rightPointer];
                        rightPointer--;
                }
        }
        res[resPointer]=nums[leftPointer]*nums[leftPointer];
        return res;        
    }
};