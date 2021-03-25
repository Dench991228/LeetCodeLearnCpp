#include "structs/ListNode.h"

using namespace std;

class Solution {
private:
    ListNode* reverseList(ListNode* head, ListNode *target) {
        if(head==nullptr)return nullptr;
        ListNode *first = head;
        ListNode *second = head->next;
        first -> next = target;
        while(second!=nullptr){
            ListNode *next = second->next;
            second->next = first;
            first = second;
            second = next;
        }
        return first;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *top = head;
        ListNode *tail = head;
        int interval = 0;
        ListNode *result = nullptr;
        while(tail!=nullptr){
            while(tail!=nullptr&&interval<k){
                tail = tail -> next;
                interval ++;
            }
            if(interval == k){//反转
                result = reverseList(top, tail);
                top = tail;
            }
            interval = 0;
        }
        return nullptr;
    }
};