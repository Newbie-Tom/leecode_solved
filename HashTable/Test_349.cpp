#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>res;
//         unordered_map<int,int>uMap1,uMap2;
//         for(auto c:nums1)uMap1[c]++;
//         for(auto d:nums2){
//             if(uMap1.count(d))
//             {
//                 uMap2[d]++;
//             }         
//         }
//         for(auto &e:uMap2){
//             if(e.second>0)
//             {
//                 res.push_back(e.first);
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>uSet1;
        unordered_set<int>uSet2(nums1.begin(),nums1.end());
        for(auto c:nums2)
        {
            if(uSet2.find(c)!=uSet2.end())
                uSet1.insert(c);
        }
        return vector<int>(uSet1.begin(),uSet1.end());
    }
};

int main()
{
    vector<int>nums1{4,9,5};
    vector<int>nums2{9,4,9,8,4};
    vector<int>res;
    Solution so;
    res = so.intersection(nums1,nums2);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}
