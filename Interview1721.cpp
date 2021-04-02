#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1)return 0;
        stack<int> current;
        current.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i ++){
            while(!current.empty() && height[current.top()] < height[i]){
                int next = current.top();
                current.pop();
                if(!current.empty()){
                    sum += (min(height[current.top()], height[i]) - next)*(i-current.top()-1);
                }
            }
            current.push(i);
        }
        return sum;
    }
};