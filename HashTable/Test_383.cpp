#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char,int>uMap;
//         for(int i=0;i<ransomNote.size();i++)
//             uMap[ransomNote[i]]++;
//         for(int i=0;i<magazine.size();i++)
//             if(uMap.count(magazine[i])){
//                 uMap[magazine[i]]--;
//             }                     
//         for(auto x:uMap)
//             if(x.second>0)
//                 return false;
//         return true;
//     }
// };
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int nums[26]={0};
        for(int i=0;i<magazine.size();i++)
        {
            nums[magazine[i]-'a']++;
        }    
        for(int i=0;i<ransomNote.size();i++)
        {
            if(nums[ransomNote[i]-'a']!=0)
                nums[ransomNote[i]-'a']--;
            else
                return false;
        }
        
        return true;
    }
};

int main()
{
    Solution so;
    string ransomNote = "fihjjjjei";
    string magazine="hjibagacbhadfaefdjaeaebgi";
    cout<<so.canConstruct(ransomNote,magazine);
    return 0;
}