#include "structs/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode *first = head;
        ListNode *second = head->next;
        first->next = nullptr;
        while(second!=nullptr){
            ListNode *next = second->next;
            second->next = first;
            first = second;
            second = next;
        }
        return first;
    }
};