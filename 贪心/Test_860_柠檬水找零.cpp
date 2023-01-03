#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //捷径条件,由于没有零钱,开头两个订单有一定的范围
        if(bills[0]>5||bills[1]>10)
            return false;
        unordered_map<int,int>uMap;
        int change = 0;
        for(int i=0;i<bills.size();i++)
        {
            uMap[bills[i]]++;   //uMap对收取的金额记录
            if(bills[i]>5)      //当需要找零时
            {
                change = bills[i]-5;
                if(change==15)
                {
                    if(uMap[10]>0)
                    {
                        uMap[10]--;
                        uMap[5]--;
                    }
                    else
                    {
                        uMap[5]-=3;
                    }
                    if(uMap[10]<0||uMap[5]<0)
                        return false;
                }
                if(change==5)
                {
                    uMap[5]--;
                    if(uMap[5]<0)
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution so;
    vector<int>bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout<<so.lemonadeChange(bills)<<endl;
}