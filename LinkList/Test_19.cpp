#include <iostream>
#include <utility>
using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        ListNode *vir_Head = new ListNode(0);
        vir_Head->next = head;
        ListNode *fast = vir_Head;
        ListNode *slow = vir_Head;
        int step = n+1;
        while (fast&&step--)
        {
            fast = fast->next;
        }
        while (slow->next&&fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        head = vir_Head->next;
        delete vir_Head;
        return head;

    }
};