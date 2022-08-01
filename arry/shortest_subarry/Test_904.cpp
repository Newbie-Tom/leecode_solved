#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
using std::vector;


// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int result=INT32_MIN;
//         int sublength =0;        vector<int> fruit_class(3,-1);
//         for(int j=0;j<fruits.size();j++)
//         {
//             if(size<2&&(fruit_class[0]!=fruits[j]&&fruit_class[1]!=fruits[j]))  //限定只能是两个种类的水果
//             {
//                 fruit_class[size++]=fruits[j];
//             }
//             else    //超过两个种类了就开始判断
//             {
//                 while(fruit_class[0]!=fruits[j]&&fruit_class[1]!=fruits[j])
//                 {
//                     sublength=(j-1)-i+1;
//                     result=result>sublength?result:sublength;
//                     if(fruit_class[0]==fruits[j-1]) //更新水果种类
//                         fruit_class[1]=fruits[j];
//                     else if(fruit_class[1]==fruits[j-1])
//                         fruit_class[0]=fruits[j];
//                     i=j-1;
//                     while ((fruits[i]==fruit_class[0]||fruits[i]==fruit_class[1])&&(fruits[i-1]==fruit_class[0]||fruits[i-1]==fruit_class[1]))
//                     {
//                         i--;
//                     }                                  
//                 }
//             }                                   
//             sublength=j-i+1;
//         }
//         result=result>sublength?result:sublength;
//         return result;        
//     }
// };



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int results=INT32_MIN;
        int size=0;

        int sublength=0;
        unordered_map<int,int>basket;
        for(int j=0;j<fruits.size();j++)
        {
            if(basket[fruits[j]]==0)
                size++;
            basket[fruits[j]]++;
            
            while (size>2)
            {
                
                if(basket[fruits[i]]==1)
                {
                    size--;  
                }
                basket[fruits[i]]--;                 
                i++;
            }
            sublength = j-i+1;
            results = max(results,sublength);
        }
        return results;
    }
};

int main()
{
    vector<int> fruits{3,3,3,1,2,1,1,2,3,3,4};
    Solution so;
    cout<<so.totalFruit(fruits)<<endl;
    return 0;
}