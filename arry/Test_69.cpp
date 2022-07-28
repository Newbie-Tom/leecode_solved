#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int mySqrt(int x) {
        
        
        if(x==0||x==1)
            return x;
        int left = 0;
        int right = x/2;    //从x的一半入手,因为平方根不会超过它的一半
        
        while (left<right)
        {
            int mid = (left+right+1)/2;
            if(x/mid<mid)   //进入[mid,right]
                right = mid-1;
            else
                left = mid;
        }

        return left;
    }
};


int main()
{
    Solution so;
    cout<<so.mySqrt(100)<<endl;
    return 0;
}