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
    ListNode* reverseList(ListNode* head) {
        
        //定义一个慢指针指向空
        ListNode *slow = NULL;
        if(head==NULL) return slow;
        ListNode *cur = head;
        ListNode *temp;
        while (cur)
        {
            temp = cur->next;
            cur->next = slow;
            slow = cur;
            cur = temp;
        }
        delete cur;
        delete temp;
        return slow;       
    }
};