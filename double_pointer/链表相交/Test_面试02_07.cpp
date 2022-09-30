
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //首先求两个链表的长度
        int lenA = 0,lenB=0;
        ListNode *pointerA=headA;
        ListNode *pointerB = headB;
        while (pointerA)
        {
                pointerA = pointerA->next;
                lenA++;
        }
        while (pointerB)
        {
                pointerB = pointerB->next;
                lenB++;
        }
        //比较两个链表的长度，使两边节点保持一致
        pointerA = headA;
        pointerB = headB;
        if(lenA>lenB)
        {
                int step = lenA-lenB;
                while (step--&&pointerA)
                {
                        pointerA = pointerA->next;
                }
                
        }
        else
        {
                int step2 = lenB-lenA;
                while (step2--&&pointerB)
                {
                        pointerB = pointerB->next;
                }
        }
        //两边指针同时运行，直至交汇于公共点
        while (pointerA&&pointerB)
        {
                if(pointerA==pointerB)
                        return pointerA;
                pointerA = pointerA->next;
                pointerB = pointerB->next;                
        }
        return NULL;
    }
};