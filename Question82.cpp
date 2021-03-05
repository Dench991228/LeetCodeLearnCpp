#include "ListNode.h"
#include <set>
#include <map>
#include <cstdlib>

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        set<int> s = set<int>();
        set<int> redundant = set<int>();
        /*先统计有哪些值是重复出现的*/
        ListNode * current = head;
        while(current != nullptr){
            if(s.find(current -> val) != s.end()){
                redundant.insert(current -> val);
            }
            s.insert(current->val);
            current = current -> next;
        }
        /*再开始删除*/
        ListNode *result = head;//最终要返回的指针，先找到一个不重复的开始
        while(result != nullptr && redundant.find(result -> val) != redundant.end()){
            result = result -> next;
        }
        current = result;
        while(current != nullptr){
            if(current -> next != nullptr && redundant.find(current -> next -> val) != redundant.end()){
                deleteNext(current -> next);
            }
            current = current -> next;
        }
        return result;
    }
private:
    /**
     * 删掉这个节点的下一个节点，务必保证下一个节点不是nullptr
     * @param current 当前的节点
    */
    void deleteNext(ListNode *current){
        current -> next = current -> next -> next;
    }
};