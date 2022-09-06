#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>need,window;
        int left=0,right=0;
        int valid = 0;
        for(auto c:s1) need[c]++;
        while (right<s2.size())
        {
            char c = s2[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(need[c]==window[c])
                    valid++; 
            }


            while (right-left>=s1.size())
            {

                if(valid==need.size())
                    return true;
                char d = s2[left];
                left++;
                if(need.count(d))
                {              
                    if(need[d]==window[d])
                    {
                        valid--;
                    }
                    window[d]--;
                }               
            }

        }
        return false;
    }
};


int main()
{
    Solution so;
    string s1 = "adc";
    string s2 = "dcda";

    cout<<so.checkInclusion(s1,s2)<<endl;
}
