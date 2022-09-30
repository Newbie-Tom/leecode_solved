#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x) ,next(NULL) {}
};



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //定义快慢指针，分别指向头指针
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast&&fast->next)
        {
            //首先：快指针走里两步,慢指针走一步
            fast = fast->next->next;
            slow = slow->next;

            // 其次，当快慢指针相遇时,确定链表有环
            if(fast==slow)
            {
                //最后：使快指针回到头节点，慢指针保持不动,两者都各走一步
                fast=head;
                while (fast!=slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
    return NULL;
    }
};