#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int skipS=0,skipT=0;
        int fastS=s.size()-1,fastT=t.size()-1;
        while (fastS>=0||fastT>=0)
        {
                while (fastS>=0)
                {
                        if(s[fastS]=='#')
                        {
                                fastS--;
                                skipS++;
                        }
                        else if(skipS>0)
                        {
                                fastS--;
                                skipS--;
                        }
                        else
                                break;
                }

                while (fastT>=0)
                {
                        if(t[fastT]=='#')
                        {
                                fastT--;
                                skipT++;
                        }
                        else if(skipT>0)
                        {
                                fastT--;
                                skipT--;
                        }
                        else
                                break;
                }
                if(fastS>=0&&fastT>=0)
                {
                        if(s[fastS]!=t[fastT])
                        {
                                return false;
                        }
                }
                else if(fastS>=0||fastT>=0)
                        return false;
                fastS--;
                fastT--;
        }
        return true;
    }
};

int main()
{
        Solution so;
        string s="bbbextm";
        string t="bbb#extm";
        cout<<so.backspaceCompare(s,t)<<endl;
        return 0;
}
