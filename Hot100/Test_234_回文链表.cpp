#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
        int val;
        ListNode *next;
        ListNode(int x): val(x),next(NULL){}
};

class Solution {
private:
        // 反转链表
        ListNode * reverseList(ListNode *Node)
        {
                ListNode *pre = NULL;
                ListNode *cur = Node;
                while (cur)
                {
                        ListNode *temp = cur;
                        cur  = cur->next;
                        temp->next = pre;
                        pre = temp;
                }
                return pre;
        }
        ListNode * firstOfHalf(ListNode *Node)
        {
                ListNode *fast = Node;
                ListNode *slow = Node;
                while (fast&&fast->next)
                {
                        slow = slow->next;
                        fast = fast->next->next;
                }
                return slow;
        }
public:
        bool isPalindrome(ListNode* head) {

                ListNode *temp = firstOfHalf(head);
                ListNode *temp2 = reverseList(temp);
                
                ListNode *temp3 =  head;
                bool res = true;
                while (temp2)
                {
                        if(temp2->val!=temp3->val)
                                return false;
                        temp2 = temp2->next;
                        temp3 = temp3->next;
                }
                temp2 = reverseList(temp2);
                return res;
        }

};



