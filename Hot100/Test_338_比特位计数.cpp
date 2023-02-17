#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



class Solution {
        private:
        int bitCount(int n)
        {
                int count=0;
                while (n)
                {
                        if(n%2)
                                count++;
                        n/=2;
                }
                return count;
        }
public:
        vector<int> countBits(int n) {
                vector<int>res(n+1,0);
                for(int i=0;i<=n;i++)
                {
                        res[i] = bitCount(i);
                }
                return res;
        }
};

// 找规律
class Solution {
public:
        vector<int> countBits(int n) {
                vector<int>res(n+1,0);
                res[0]=0;
                for(int i=1;i<=n;i++)
                {
                        if(i%2)
                                res[i] = res[i-1]+1;
                        else
                                res[i] = res[i/2];               
                }
                return res;
        }
};