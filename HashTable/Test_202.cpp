#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
    private:
    int getSum(int n)
    {
        int sum=0;
        while (n)
        {
            sum +=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        // int sum=getSum(n);
        // unordered_map<int,int>uMap;       
        // uMap[sum]++;
        // while (sum)
        // {
        //     if(sum==1)
        //         return true;
        //     if(uMap[sum]>1)
        //         return false;
        //     else
        //         uMap[sum]++;
        //     sum = getSum(sum); 
        // }
        // return false; 
        unordered_set<int>uSet;
        int sum=0;
        while (1)
        {
            sum = getSum(n);
            if(sum==1)
                return true;
            
            if(uSet.find(sum)!=uSet.end())
                return false;
            else
                uSet.insert(sum);
            
            n = sum;
            
        }
    }
};