#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1&&!list2)
            return NULL;
        else if(!list1&&list2)
            return list2;
        else if(!list2&&list1)
            return list1;
        
        ListNode *l1Cur = list1;
        ListNode *l2Cur = list2;
        ListNode *list3 = new ListNode(0);
        list3->next = NULL;
        ListNode *l3Cur = list3;

        while (l1Cur&&l2Cur)
        {
            if(l1Cur->val<=l2Cur->val)
            {
                ListNode *temp = new ListNode(0);
                temp->val = l1Cur->val;
                temp->next = NULL;
                l3Cur->next = temp;
                l3Cur = l3Cur->next;
                l1Cur = l1Cur->next;
            }
            else{
                
                ListNode *temp = new ListNode(0);
                temp->val = l2Cur->val;
                temp->next = NULL;
                l3Cur->next = temp;
                l3Cur = l3Cur->next;
                l2Cur = l2Cur->next;
            }
        }
        while (l1Cur)
        {
            ListNode *temp = new ListNode(0);
                temp->val = l1Cur->val;
                temp->next = NULL;
                l3Cur->next = temp;
                l3Cur = l3Cur->next;
                l1Cur = l1Cur->next;
        }
        while (l2Cur)
        {
            ListNode *temp = new ListNode(0);
                temp->val = l2Cur->val;
                temp->next = NULL;
                l3Cur->next = temp;
                l3Cur = l3Cur->next;
                l2Cur = l2Cur->next;
        }
        list3 = list3->next;
        return list3;
    }
};

int main(int argc, const char** argv) {
    Solution so;
    
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = NULL;
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = NULL;
    ListNode *list3 = so.mergeTwoLists(list1,list2);
    return 0;
}