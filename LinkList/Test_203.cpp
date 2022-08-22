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

// //非虚拟头结点
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
       
//        //若头节点的值需被删除,删除头节点
       
//        while (head!=NULL&&head->val==val)
//        {    //新建一个节点指向头节点后的节点
//             ListNode *temp = head;
//             //原头节点往后移一位
//             head = head->next;
//             //删除原头节点
//             delete temp;
//        }
//         //删除非头节点
//        ListNode *cur = head;
//        //遍历链表
//        while (cur!=NULL&&cur->next!=NULL)
//        {
//             //若该节点的下一个节点为待删除节点
//             if(cur->next->val==val)
//             {
//                 //新建一个节点指向该节点
//                 ListNode *temp = cur->next;
//                 cur->next = temp->next;
//                 delete temp;
//             }   
//             else
//             {
//                 cur= cur->next;
//             }     
//        }
        
//         return head;
//     }
// };

//虚拟头节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //创建一个虚拟头节点指向头节点
        ListNode *vir_head = new ListNode(0);
        vir_head->next= head;
        ListNode *cur = vir_head;
        while (cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                ListNode *temp = cur->next;
                cur ->next= temp->next;
                delete temp;
            }   
            else{
                cur = cur->next;
            }
        }
        head = vir_head->next;
        delete vir_head;
        return head;
    }
};





