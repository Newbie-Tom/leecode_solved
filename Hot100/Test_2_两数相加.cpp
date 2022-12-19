#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *l1Cur = l1;
        ListNode *l2Cur = l2;
        ListNode *fakeNode = new ListNode(0);
        fakeNode->next = l1;
        ListNode *tp = fakeNode;
        while (l1Cur&&l2Cur)
        {
            sum+=l1Cur->val+l2Cur->val;
            if(sum>=10)
            {
                int temp = sum%10;
                l1Cur->val = temp;
                sum = sum/10;   
            }
            else
            {
                l1Cur->val = sum;
                sum=0;
            }
            l1Cur = l1Cur->next;
            l2Cur = l2Cur->next;
            tp = tp->next;
        }
        while (l1Cur)
        {
            sum+=l1Cur->val;
            if(sum>=10)
            {
                int temp = sum%10;
                l1Cur->val = temp;
                sum = sum/10;   
            }
            else
            {
                l1Cur->val = sum;
                sum=0;
            }
            l1Cur = l1Cur->next;
            tp = tp->next;
        }
        while (l2Cur)
        {
            sum+=l2Cur->val;
            if(sum>=10)
            {
                int temp = sum%10;
                ListNode *Node = new ListNode(temp);
                tp->next = Node;
                Node->next = NULL;
                sum = sum/10;   
            }
            else
            {
                ListNode *Node = new ListNode(sum);
                tp->next = Node;
                Node->next = NULL;
                sum=0;
            }
            l2Cur = l2Cur->next;
            tp = tp->next;
        }
        if(sum!= 0)
        {
            ListNode *node = new ListNode(sum);
            tp->next = node;
            node->next =NULL;
            delete fakeNode;
        }
        return l1;
    }
};