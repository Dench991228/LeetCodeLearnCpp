#include "structs/ListNode.h"

using namespace std;
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode *first = head;
        ListNode *second = head->next;
        while(second!=nullptr){
            ListNode *next = second->next;
            second->next = first;
            first = second;
            second = next;
        }
        return first;
    }
public:
    /**
     * 找到后半部分的开始节点然后把后半部分反转，然后和前半部分一块开始一一合并
    */
    void reorderList(ListNode* head) {
        //慢指针一次走两格，等快指针到了nullptr，则慢指针指向下半部分开头
        ListNode *slow = head;//慢指针
        ListNode *fast = head;//快指针
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast!=nullptr)fast = fast->next;
        }
        if(slow == head){//只有一个元素
            return;
        }
        ListNode *l = head;
        while(l->next!=slow){
            l = l->next;
        }
        l->next = nullptr;
        slow = reverseList(slow);//反转链表
        if(slow != head){
            ListNode *h = head;//遍历head
            ListNode *s = slow;//遍历slow
            while(h!=nullptr&&s!=nullptr){
                ListNode *h_next = h -> next;
                ListNode *s_next = s -> next;
                h -> next = s;
                s -> next = h_next;
                h = h_next;
                s = s_next;
            }
        }
    }
};