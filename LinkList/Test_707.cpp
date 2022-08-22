#include <iostream>
#include <utility>
using namespace std;



class MyLinkedList {
private:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode *head;
public:
    MyLinkedList() :head(nullptr) {   
         
    }
    
    int get(int index) {
        if(index>=0)
        {
            int size = 0;
            //定义一个新节点指向头结点
            ListNode *cur=new ListNode(0);
            cur->next = head;
            while (cur->next&&size<index)
            {
                //遍历链表
                cur = cur->next;
                size++;
            }
            if(cur->next&&size==index)
                return cur->next->val;
            else if(!cur->next||size<index)
                return -1;    
        }
        else
            return -1;        
    }
    
    void addAtHead(int val) {
        //创建一个新节点
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head = temp;
    
    }
    
    void addAtTail(int val) {
        //创建一个新节点
        int size=0;        
        ListNode *temp = new ListNode(val);
        ListNode *vir_Head = new ListNode(0);
        vir_Head->next = head;
        ListNode *cur = vir_Head;
        while (cur->next)
        {
            cur = cur->next;   
            size++;
        }
        temp->next = NULL;
        cur->next = temp;
        head = vir_Head->next;
        delete vir_Head;
    }
    
    void addAtIndex(int index, int val) {
        int size =0;
        if(index<=0)
        {
            ListNode *p = new ListNode(val);
            p->next = head;
            head = p;

        }
        else{
            //新建一个虚拟头节点
            ListNode *cur= new ListNode(0);
            cur->next = head;
            //判断当前节点不为空且尺寸未到index
            while (cur->next&&size<index)
            {
                cur = cur->next;
                size++;   
            }
            //若为空节点,不作处理
            if(cur->next==NULL&&size==0);
            //链表长度小于index,不作处理
            if (cur->next==NULL&&size<index);
            //链表长度等与index            
            if(cur->next==NULL&&size==index)
            {
                ListNode *temp = new ListNode(val);
                temp->next = NULL;
                cur->next = temp;
                cur = cur->next;
            }
            //到索引的位置且,节点不为空
            if(cur->next!=NULL&&size==index)
            {
                //新建一个节点
                ListNode *temp = new ListNode(val);
                temp->next = cur->next;
                cur->next = temp;
                cur = cur->next;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        int size = 0;
        //索引有效
        if(index>=0)
        {
            //创建一个虚拟头节点
            ListNode *cur = new ListNode(0);
            cur->next = head;
            
            //遍历
            while (cur->next&&size<index)
            {
                cur=cur->next;
                size++;
            }
            //到达索引的位置
            if(cur->next!=NULL&&size==index)
            {
                ListNode *temp = cur->next;
                cur->next = temp->next;                
                delete temp;
            }
            if(index==0)
                head = head->next;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(void)
{
    MyLinkedList *obj = new MyLinkedList();
    // obj->addAtHead(5);
    // int param_1 = obj->get(0);
    // cout<<param_1<<endl;
    // obj->addAtTail(4);
    // obj->addAtTail(3);
    // int temp = obj->get(2);
    // cout<<temp<<endl;
    // obj->addAtIndex(1,15);
    // temp = obj->get(1);
    // cout<<temp<<endl;
    // obj->addAtIndex(5,10);
    // temp = obj->get(3);
    // cout<<temp<<endl;
    // obj->addAtIndex(-1,19);
    // temp = obj->get(0);
    // cout<<temp<<endl;
    // obj->addAtHead(1);
    // obj->addAtTail(3);
    // obj->addAtIndex(1,2);
    // int temp = obj->get(1);
    // cout<<temp<<endl;
    // obj->deleteAtIndex(0);
    // temp= obj->get(0);
    // cout<<temp<<endl;

    // obj->deleteAtIndex(0);
    obj->addAtTail(1);
    int temp = obj->get(0);
    cout<<temp<<endl;
    return 0;
}