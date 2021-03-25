#include <deque>

using namespace std;

class MaxQueue {
private:
    deque<int> dq;
    deque<int> decrease_stack;
public:
    MaxQueue() {
        dq = deque<int>();
        decrease_stack = deque<int>();
    }
    
    int max_value() {
        if(decrease_stack.empty())return -1;
        return decrease_stack.front();
    }
    
    void push_back(int value) {
        dq.push_back(value);
        while(!decrease_stack.empty()&&decrease_stack.back()<value){
            decrease_stack.pop_back();
        }
        decrease_stack.push_back(value);
    }
    
    int pop_front() {
        if(dq.empty())return -1;
        int result = dq.front();
        dq.pop_front();
        if(decrease_stack.front()==result){
            decrease_stack.pop_front();
        }
        return result;
    }
};