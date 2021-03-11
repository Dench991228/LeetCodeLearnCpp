#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

bool isnumber(char c){
    return c<='9'&&c>='0';
}

class lexelItem{
private:
    int val;
    char op;
    bool type;//类型：操作数为true，运算符为false
public:

    lexelItem(char c){
        this -> op = c;
        this -> type = false;
    }

    lexelItem(int v){
        this -> val = v;
        this -> type = true;
    }

    bool isNumber(){
       return type; 
    }

    int getValue(){
        return this->val;
    }

    char getOp(){
        return this->op;
    }
};
class Solution{
private:
    string::iterator pos;//指向当前已经解析完的部分
    string expression;//待解析的式子
    queue<lexelItem> state_queue = queue<lexelItem>();//解析过程中的状态栈
    stack<lexelItem> operator_stack = stack<lexelItem>();//解析过程中没有弹出的符号
    /**
     * 跳过expression中目前为止的空格
    */
    void skipBlank(){
        while(pos != expression.end() && (*pos) == ' '){
            pos++;
        }
    }
    /**
     * 从当前的expression的位置获得一个词法单元
    */
    void getLexelItem(){
        skipBlank();
        if(pos==expression.end()){
            return;
        }
        if(isnumber(*pos)){//如果是个数字
            string operand;
            while(pos != expression.end() && isnumber((*pos))){
                operand.append(1, (*pos));
                pos++;
            }
            //cout << "a number was found: " << operand << endl;
            lexelItem it(stoi(operand));
            state_queue.push(it);
        }else{
            char opr = (*pos);
            pos++;
            lexelItem it(opr);
            //cout << "a operator was found: " << opr << endl;
            switch(opr){
                case '(':
                    operator_stack.push(it);
                    break;
                case ')':
                    while(!operator_stack.empty() && (operator_stack.top().getOp()!='(')){
                        lexelItem lt = operator_stack.top();
                        operator_stack.pop();
                        state_queue.push(lt);
                    }
                    operator_stack.pop();
                    break;
                case '*':
                case '/':
                    while(!operator_stack.empty()&&(operator_stack.top().getOp()=='*'||operator_stack.top().getOp()=='/')){
                        lexelItem lt = operator_stack.top();
                        operator_stack.pop();
                        state_queue.push(lt);
                    }
                    operator_stack.push(it);
                    break;
                case '+':
                case '-':
                    while(!operator_stack.empty() && (operator_stack.top().getOp()!='(')){
                        lexelItem lt = operator_stack.top();
                        operator_stack.pop();
                        state_queue.push(lt);
                    }
                    operator_stack.push(it);
                    break;
            }
        }
    }
public:
    int calculate(string s) {
        expression = s;
        pos = expression.begin();
        while(pos != expression.end()){
            getLexelItem();
        }
        while(!operator_stack.empty()){
            lexelItem lt = operator_stack.top();
            operator_stack.pop();
            state_queue.push(lt);
        }
        stack<int> number = stack<int>();
        while(!state_queue.empty()){
            lexelItem it = state_queue.front();
            state_queue.pop();
            if(it.isNumber()){//如果是数字，就推进去
                //cout << it.getValue() << " was out" << endl;
                number.push(it.getValue());
            }else{
                //cout << it.getOp() << " was out" << endl;
                int number_two = number.top();
                number.pop();
                int number_one = number.top();
                number.pop();
                int result = 0;
                switch(it.getOp()){
                    case '+':
                        result = number_one + number_two;
                        break;
                    case '-':
                        result = number_one - number_two;
                        break;
                    case '*':
                        result = number_one * number_two;
                        break;
                    case '/':
                        result = number_one / number_two;
                        break;
                }
                number.push(result);
            }
        }
        return number.top();
    }
};

int main(){
    string str;
    Solution s;
    while(cin >> str){
        cout << str << " = " << s.calculate(str) << endl;
    }
    return 0;
}