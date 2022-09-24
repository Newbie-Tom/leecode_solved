#include <iostream>
using namespace std;


struct ListNode
{
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //1、定义两个节点，其中pre节点指向NULL，cur节点指向head
        ListNode *pre = NULL;
        ListNode *cur = head;
        //2、一直移动cur节点，直至指向NULL，中间一直改变指针方向
        while (cur)
        {
                ListNode *temp = cur;
                cur = cur->next;
                temp->next = pre;
                pre = temp;
        }
        //3、返回pre
        return pre;
    }
};

