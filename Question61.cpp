#include "structs/ListNode.h"

using namespace std;

class Solution {
public:
    /**
     * 对一个链表进行k次右旋，相当于是把最后的k个节点放在头上
    */
    ListNode* rotateRight(ListNode* head, int k) {
        //先计算链表的长度
        ListNode *cur = head;
        int len = 0;
        while(cur!=nullptr){
            cur = cur -> next;
            len ++;
        }
        k %= len;
        cur = head;
        ListNode *tail = cur;
        if(k!=0){
            for(int i=0;i<k;i++){
                tail = tail -> next;
            }
            // cur指向要被挪到前面的部分的第一个节点
            // tail指向最后一个节点
            while(tail->next!=nullptr){
                tail = tail -> next;
                cur = cur -> next;
            }
            ListNode *result = cur -> next;
            tail -> next = head;
            cur -> next = nullptr;
            return result;
        }
        else return head;
    }
};