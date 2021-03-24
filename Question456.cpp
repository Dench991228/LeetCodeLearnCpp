#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> increase_stack;
        for(int i:nums){
            bool popped = false;
            while(!increase_stack.empty()){
                if(increase_stack.top()>i){
                    increase_stack.pop();
                    popped = true;
                }else{
                    break;
                }
            }
            if(popped&&!increase_stack.empty())return true;
            increase_stack.push(i);
        }
        return false;
    }
};