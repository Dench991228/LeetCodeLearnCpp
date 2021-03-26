#include "structs/ListNode.h"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while(cur!=nullptr){
            if(cur->next!=nullptr&& cur->next->val == cur->val){
                cur -> next = cur -> next -> next;
            }
            cur = cur -> next;
        }
        return head;
    }
};