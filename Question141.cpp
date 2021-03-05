#include "structs/ListNode.h"
#include <iostream>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        do{
            slow = slow -> next;
            fast = fast -> next;
            if(fast != nullptr){
                fast = fast -> next;
            }
        }while(slow != nullptr && fast != nullptr && fast != slow);
        if(slow != nullptr && slow == fast)return true;
        else return false;
    }
};