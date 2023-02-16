#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
        int LengthOfLinkList(ListNode *Head)
        {
                int length = 0;
                ListNode *cur = Head;
                while (cur!=NULL)
                {
                        length++;
                        cur = cur->next;
                }
                return length;
        }
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

                ListNode *CurA = headA;
                ListNode*CurB = headB;
                int lengthA = LengthOfLinkList(CurA);
                int lengthB=LengthOfLinkList(CurB);
                if(lengthA<lengthB)
                {
                        swap(CurA,CurB);
                        swap(lengthA,lengthB);
                }
                int  val = lengthA-lengthB;
                while (val)
                {
                        CurA = CurA->next;
                        val--;
                }
                while (CurA)
                {
                        if(CurA==CurB)
                        {
                                return CurA;
                        }
                        CurA = CurA->next;
                        CurB = CurB->next;
                }
                return NULL;
        }       
};