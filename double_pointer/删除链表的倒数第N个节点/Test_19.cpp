#include  <iostream>
using namespace std;



 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                ListNode *virtualHead = new ListNode(0);
                virtualHead->next = head;
                ListNode *slow = virtualHead;
                ListNode *fast=virtualHead;
                //首先fast走n+1步
                int step=n+1;
                while (step--&&fast)
                {
                        fast = fast->next;
                }
                //随后fast和slow同时走，直至fast指向NULL
                while (slow->next&&fast)
                {
                        fast = fast->next;
                        slow = slow->next;
                }
                //当fast指向空时，slow指向待删除的上一节点，执行删除步骤
                ListNode *temp = slow->next;
                slow->next = temp->next;
                delete temp;
                head = virtualHead->next;
                delete virtualHead;
                //返回头节点
                return head;                     
    }
};
