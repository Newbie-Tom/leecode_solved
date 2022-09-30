#include <iostream>
#include <queue>
using namespace std;


class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);

    }
    
    int pop() {
        int size = q1.size();
        if(q2.empty())
        {
            while (size>1)
            {
                //备份
                q2.push(q1.front());
                q1.pop();
                size--;
            }
        }
        int res = q1.front();
        q1.pop();
        if(q1.empty())
        {
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }       
        }
        return res;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};