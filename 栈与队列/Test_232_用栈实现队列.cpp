#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> stIN;
    stack<int> stOUT;
    MyQueue() {

    }
    
    void push(int x) {
        stIN.push(x);
    }

    int pop() {
        if(stOUT.empty()){
          while (!stIN.empty())
            {
                stOUT.push(stIN.top());
                stIN.pop();
            }  

        }
        int temp = stOUT.top();
        stOUT.pop();
        return temp;
    }


    int peek() {
        int temp = this->pop();
        stOUT.push(temp);
        return temp;
        
    }
    
    bool empty() {
        return stIN.empty()&&stOUT.empty();
    }
};
class MyQueue {
public:
    stack<int> stIN;
    stack<int> stOUT;
    MyQueue() {

    }
    
    void push(int x) {
        stIN.push(x);
    }
    
    int pop() {
        if(stOUT.empty()){
          while (!stIN.empty())
            {
                stOUT.push(stIN.top());
                stOUT.pop();
            }  

        }
        int temp = stOUT.top();
        stOUT.pop();
        return temp;
    }

    int peek() {
        int temp = this->pop();
        stOUT.push(temp);
        return temp;
        
    }
    
    bool empty() {
        return stIN.empty()&&stOUT.empty();
    }
};
