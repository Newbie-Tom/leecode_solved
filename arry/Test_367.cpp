#include <iostream>
#include <vector>
using namespace std;
using std::vector;


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num ==0||num==1) //直接返回
        {
            return true;
        }
        int left=0; //(左闭右闭原则)
        int right=num;
        while (left<=right)
        {
            int mid = (left+right)/2;
            if((long)mid*mid>num)
            {
                right = mid-1;
            }
            else if((long)mid*mid<num)
            {
                left = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution so;
    cout<<so.isPerfectSquare(3)<<endl;
    return 0;
}




















