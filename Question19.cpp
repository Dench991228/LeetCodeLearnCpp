#include "structs/ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *former = nullptr;//指向被删除节点的节点
        ListNode *target = head;//被删除的节点
        ListNode *end = head;//被删除节点后n个节点的节点
        for(int i = 0; i < n; i++){
            end = end -> next;
        }
        while(end!=nullptr){
            former = target;
            target = target -> next;
            end = end -> next;
        }
        if(former == nullptr)return head->next;
        else{
            former -> next = former -> next -> next;
            return head;
        }
    }
};