#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// class Solution {
//         private:
//                 int diffCount (int x,int y)
//                 {
//                         int count = 0;
//                         while (max(x,y))
//                         {
//                                 int x2 = x%2;
//                                 int y2 = y%2;
//                                 if(x2^y2)
//                                         count++;
//                                 x/=2;
//                                 y/=2;
//                         }
//                         return count;
//                 }
// public:
//         int hammingDistance(int x, int y) {
//                 return diffCount(x,y);
//         }
// };

// 异或和与运算符
class Solution {
public:
        int hammingDistance(int x, int y) {
                int diff=0;
                int z = x^y;
                while (z)
                {
                        diff += z&1;
                        z>>=1;
                }
                return diff;
        }
};

int main()
{
        int x=1,y=4;
        Solution so;
        cout<<so.hammingDistance(x,y);
}