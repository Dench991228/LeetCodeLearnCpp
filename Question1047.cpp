#include <string>
#include <deque>

using namespace std;

class Solution{
public:
    string removeDuplicates(string S) {
        deque<char> myDq;
        for(char c:S){
            if(!myDq.empty()&&myDq.back()==c){
                myDq.pop_back();
                continue;
            }
            myDq.push_back(c);
        }
        string result;
        for(char c:myDq){
            result.append(1, c);
        }
        return result;
    }
};