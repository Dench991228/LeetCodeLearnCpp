#include <iostream>
#include "structs/ListNode.h"

using namespace std;

class Solution {
public:
    /**
     * 交换一个链表中所有节点与其相邻节点
     * @param head 被交换的链表的第一个元素
     * @return 交换后的链表的第一个元素
    */
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)return nullptr;
        ListNode *result = swapNeighbor(head);
        ListNode *former = result -> next;
        if(result -> next == nullptr){
            return result;
        }
        ListNode *current = result -> next -> next;
        while(current != nullptr){
            current = swapNeighbor(current);
            former -> next = current;
            current = current -> next;
            former = current;
            if(current != nullptr)current = current -> next;
        }
        return result;
    }
private:
    /**
     * 交换两个相邻节点，返回current原来的后继节点
     * @param current 需要和后继节点交换的节点
     * @return 返回current交换前的后继节点，如果current没有后继节点，就是current
    */
    ListNode* swapNeighbor(ListNode *current){
        if(current == nullptr){
            return current;
        }else if(current -> next == nullptr){
            return current;
        }else{
            ListNode *next = current -> next;
            current -> next = next -> next;
            next -> next = current;
            return next;
        }
    }
};