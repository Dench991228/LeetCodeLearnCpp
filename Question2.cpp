#include "structs/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *current = result;
        ListNode *cur_1 = l1, *cur_2 = l2;
        while(cur_1 != nullptr && cur_2 != nullptr){
            current->val += cur_1 -> val + cur_2 -> val;
            current->next = new ListNode(0);
            current = current -> next;
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }
        while(cur_1 != nullptr){
            current->val += cur_1 -> val;
            current->next = new ListNode(0);
            current = current -> next;
            cur_1 = cur_1->next;
        }
        while(cur_2 != nullptr){
            current->val += cur_2 -> val;
            current->next = new ListNode(0);
            current = current -> next;
            cur_2 = cur_2->next;
        }
        ListNode *begin = new ListNode(0, result);
        current = begin;
        while(current->next != nullptr){
            if(current->val >= 10){
                current->val -= 10;
                current -> next -> val ++;
            }
            if(current->next->next==nullptr&&current->next->val==0){
                current->next=nullptr;
            }
        }
        return result;    
    }
};