#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> stk;
        for(int i=0;i<T.size();i++){
            while(!stk.empty() && T[stk.top()]<T[i]){
                int pos = stk.top();
                result[pos] = i-pos;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};