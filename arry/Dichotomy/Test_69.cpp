#include <iostream>
#include <vector>
using namespace std;
using std::vector;

// class Solution {
// public:
//     int mySqrt(int x) {
        
        
//         if(x==0||x==1)
//             return x;
//         int left = 0;
//         int right = x/2;    //从x的一半入手,因为平方根不会超过它的一半
        
//         while (left<right)
//         {
//             int mid = (left+right+1)/2;
//             if(x/mid<mid)   //进入[left,mid-1]
//                 right = mid-1;
//             else
//                 left = mid;
//         }

//         return left;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0||x==1)
            return x;
        int left = 0;
        int right = x;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if((long)mid*mid<=x)
            {
                left=mid+1;   
            }
            else{   //[left,mid-1]
                right=mid-1;
            }    
        }
        return left-1;   
    }
};


int main()
{
    Solution so;
    cout<<so.mySqrt(20)<<endl;
    return 0;
}