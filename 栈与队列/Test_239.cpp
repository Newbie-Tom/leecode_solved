#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class MyQueue{

    public:
    deque<int> Deque;
    MyQueue(){

    }  
    void pop(int value)
    {
        if(!Deque.empty()&&value==Deque.front())
        {
            Deque.pop_front();
        }
    }
    void push(int x)
    {
        while(!Deque.empty()&&x>Deque.back())
        {
            Deque.pop_back();
        }
        Deque.push_back(x);
    }
    int front()
    {
        return Deque.front();
    }
    
};
    


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int>result;
        for(int i=0;i<k;i++)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i=k;i<nums.size();i++)
        {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};


int main()
{
    Solution so;
    vector<int> result;
    vector<int>nums{1,3,-1,-3,5,3,6,7}; int k=3;
    result=so.maxSlidingWindow(nums,3);
    for(auto c:result)
        cout<<c<<endl;
    return 0;
}