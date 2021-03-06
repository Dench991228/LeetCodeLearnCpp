#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result = vector<int>(nums.size(), -1);
        stack<int> my_stack;
        int len = nums.size();
        for(int i=0;i<len*2-1;i++){
            while(!my_stack.empty() && nums[my_stack.top()] < nums[i%len]){
                int pos = my_stack.top();
                my_stack.pop();
                result[pos] = nums[i%len];
            }
            my_stack.push(i%len);
        }
        return result;
    }
};