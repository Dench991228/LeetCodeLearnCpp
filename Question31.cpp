#include <string>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
private:
    /**
     * 从这个字符串中读出下一个有价值的内容，并且移动it，注意，调用的时候it不能是s.end()
     * @param s 目标字符串
     * @param it 当前读到了这个字符串的哪里
     * @return 下一个有价值的内容，要么是一个整数，要么是一个#
    */
    char getNext(string &s, string::iterator &it){
        while(it != s.end() && (*it) == ','){
            it ++;
        }
        char result = (*it);
        while(it!= s.end() && (((*it)>='0'&&(*it)<='9')||(*it)=='#')){
            it++;
        }
        return result;
    }
public:
    bool isValidSerialization(string preorder) {
        deque<char> waiting_list;//等待被找到儿子的节点
        deque<int> waiting_state;//等待状态，0就是没儿子，1是左儿子被找到，2是右儿子被找到
        string::iterator it = preorder.begin();
        char c = getNext(preorder, it);
        if(c != '#'){
            waiting_list.push_back(getNext(preorder, it));
            waiting_state.push_back(0);
        }
        while(it != preorder.end()){
            char element = getNext(preorder, it);
            if(waiting_list.empty())return false;//没有爹，就有问题
            int father_state = waiting_state.back();//父节点的状态
            waiting_state.pop_back();
            waiting_state.push_back(father_state+1);
            if(element=='#'){//不断弹出状态为2的父节点
                cout << "pushing: "<< element << endl;
                while(!waiting_state.empty() && waiting_state.back()==2){
                    cout << "poping: "<< waiting_list.back() << endl;
                    waiting_state.pop_back();
                    waiting_list.pop_back();
                }
            }else{//入栈
                cout << "pushing: "<< element << endl;
                waiting_list.push_back(element);
                waiting_state.push_back(0);
            }
        }
        return waiting_list.empty();
    }
};

int main(){
    string input;
    while(cin >> input){
        Solution s;
        cout << s.isValidSerialization(input) << endl;
    }
    return 0;
}