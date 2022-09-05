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
    ListNode* swapPairs(ListNode* head) {
        //创建一个虚拟头节点
        ListNode *vir_Head = new ListNode(0);
        vir_Head->next = head;
        ListNode *cur = vir_Head;
        
        while (cur->next&&cur->next->next)
        {
            //创建两个临时节点,保存待交换的两个节点
            ListNode *temp1 = cur->next;
            ListNode *temp2 = cur->next->next->next;

            //eg:
            //步骤1:cur指向2
            cur->next = cur->next->next;
            //步骤2:2指向1
            cur->next->next = temp1;
            //步骤3:1指向3
            temp1->next = temp2;

            cur = cur->next->next;
        }
        head = vir_Head->next;
        delete vir_Head;
        return head;        

    }
};