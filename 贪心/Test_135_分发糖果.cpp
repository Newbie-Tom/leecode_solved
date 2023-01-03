#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0;
        //题目规定每个孩子至少分配到一个糖果
        vector<int> candyVec(ratings.size(),1);
        //从左到右遍历,如果右边的比左边的评分高,则右边的孩子多分到一个糖果
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                candyVec[i]=candyVec[i-1]+1;

        }
        //从右向左遍历,如果左边的孩子比右边的孩子分值高,此时candyVec[i]（第i个小孩的糖果数量）就有两个选择了，
        //一个是candyVec[i + 1] + 1（从右边这个加1得到的糖果数量），一个是candyVec[i]（之前比较右孩子大于左孩子得到的糖果数量）。
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                candyVec[i] = max(candyVec[i],candyVec[i+1]+1);
        }
        for(int i=0;i<candyVec.size();i++)
        {
            sum+= candyVec[i];
        }
        return sum;
    }
};