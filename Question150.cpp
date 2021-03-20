#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(string token: tokens){
            if((token[0]>='0'&&token[0]<='9')||(token.length()>1&&token[0]=='-')){//是一个数字
                numbers.push(stoi(token));
            }else{
                int number_two = numbers.top();
                numbers.pop();
                int number_one = numbers.top();
                numbers.pop();
                switch(token[0]){
                    case '+':
                        numbers.push(number_one + number_two);
                        break;
                    case '-':
                        numbers.push(number_one - number_two);
                        break;
                    case '*':
                        numbers.push(number_one * number_two);
                        break;
                    case '/':
                        numbers.push(number_one / number_two);
                        break;
                }
            }
        }
        return numbers.top();
    }
};