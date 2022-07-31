#include <iostream>
#include <vector>
using namespace std;
using std::vector;


// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//        /*第一步找到中间值并求其平均值*/
//        int mid = findmidposition(nums);
//        vector<int> NUMS(nums.size());
//        /*三种情况:1.单调增 2.单调减 3.抛物线*/
//        if(mid==0)
//             return nums;
//        else if(mid==nums.size()-1)
//             {
//                 int i=0;
//                 while (mid>=0)
//                 {
//                     NUMS[i++] = nums[mid--];
//                 }
//                 return NUMS;
//             }
//         else
//         {
//             int left = mid-1;
//             int right = mid+1;
//             NUMS[0]=nums[mid];
//             int i= 1;
//             while(left>=0&&right<=nums.size()-1)
//             {
//                 if(nums[left]<nums[right])
//                 {
//                     NUMS[i++]=nums[left];
                   
//                     left--;
//                 }
//                 else
//                 {
//                     NUMS[i++]=nums[right];
//                     right++;
//                 }
//             }
//             int length = NUMS.size()-1;
//             int j=0;
//             while (left>=0)
//             {
//                 NUMS[length]=nums[j];
//                 length--;
//                 left--;
//                 j++;
//             }
//             while (right<=nums.size()-1)
//             {
//                 NUMS[i++]=nums[right++];  
//             }   
//             return NUMS;
//         }       
//     }
// private:
//     int findmidposition(vector<int>& nums)
//     {   
//         int mid = 0;
//         for(int i=0;i<nums.size();i++)
//         {
//             nums[i]*=nums[i];   //求平方
//             if(nums[i]<nums[mid])
//             {
//                 mid =i;    
//             }   
//         }
//         return mid;   
//     }
// };

// //左右双指针
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//        int left = 0;    //头指针
//        int right = nums.size()-1;   //尾指针
//        vector<int> results(nums.size());
//        int k = results.size()-1;
//         while(left<=right)
//         {
//             if(nums[left]*nums[left]>nums[right]*nums[right])   //左边是大的一方
//             {
//                 results[k--] = nums[left]*nums[left];
//                 left++;
//             }
//             else    //右边是大的一方
//             {
//                 results[k--] = nums[right]*nums[right];
//                 right--;
//             }
//         }
//         return results;           
//     }
// };

//快速排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //第一步,求平方
        for(int i=0;i<nums.size();i++)
        {
            nums[i]*=nums[i];   //求平方
        }
        //第二步,快速排序
        // vector<int> results(nums.size());
        int left=0;
        int right = nums.size()-1;
        quicksort(nums,left,right);
        return nums;
    }
    private:
    void quicksort(vector<int>& nums,int left,int right)
    {
        if(left<right){
            int temp=nums[left];   //用第一个数作为分界
            vector<int> results(nums.size());        
            int i = left;
            int j = right;
            while (i<j)
            {
                while (i<j&&nums[j]>=temp)  //最右端的数比分界数大
                {
                    j--;    
                }
                nums[i] = nums[j];
                while (i<j&&nums[i]<=temp)
                {
                    i++;
                }
                nums[j] = nums[i];            
            }
            nums[i]=temp;

            quicksort(nums,left,i-1);
            quicksort(nums,i+1,right);
            }
        else
            return;
    }
//     void quickSort(vector<int> &arr,int begin,int end)
// {
// 	//如果区间不只一个数
// 	if(begin < end)
// 	{
// 		int temp = arr[begin]; //将区间的第一个数作为基准数
// 		int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
// 		int j = end; //从右到左进行查找时的“指针”，指示当前右位置
// 		//不重复遍历
// 		while(i < j)
// 		{
// 			//当右边的数大于基准数时，略过，继续向左查找
// 			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
// 			while(i<j && arr[j] > temp)
// 				j--;
// 			//将右边小于等于基准元素的数填入右边相应位置
// 			arr[i] = arr[j];
// 			//当左边的数小于等于基准数时，略过，继续向右查找
// 			//(重复的基准元素集合到左区间)
// 			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
// 			while(i<j && arr[i] <= temp)
// 				i++;
// 			//将左边大于基准元素的数填入左边相应位置
// 			arr[j] = arr[i];
// 		}
// 		//将基准元素填入相应位置
// 		arr[i] = temp;
// 		//此时的i即为基准元素的位置
// 		//对基准元素的左边子区间进行相似的快速排序
// 		quickSort(arr,begin,i-1);
// 		//对基准元素的右边子区间进行相似的快速排序
// 		quickSort(arr,i+1,end);
// 	}
// 	//如果区间只有一个数，则返回
// 	else
// 		return;
// }

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


