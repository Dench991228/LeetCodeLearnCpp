#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<char> > dtoc = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    bool add(vector<vector<char>::iterator> &iters, vector<vector<char> > &possibility){
        int i = iters.size()-1;
        //cout << (iters[0] == possibility[0].begin()) << endl;
        while(i>0){
            iters[i]++;
            if(iters[i] == possibility[i].end()){
                iters[i] = possibility[i].begin();
            }else{
                return true;
            }
            i--;
        }
        iters[0]++;
        return iters[0] != possibility[0].end();
    }

    string toString(vector<vector<char>::iterator> &iters){
        string result;
        for(vector<char>::iterator iter:iters){
            result.append(1, (*iter));
        }
        return result;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)return result;
        vector<vector<char>::iterator > iterators;
        vector<vector<char> > possibility;
        for(char c:digits){
            vector<char> *temp = new vector<char>(dtoc[c-'0']);
            possibility.emplace_back(*temp);
            iterators.emplace_back((*temp).begin());
            iterators.back() = possibility.back().begin();
        }
        //cout << "intialization ok" << endl;
        result.push_back(toString(iterators));
        while(add(iterators, possibility)){
            result.push_back(toString(iterators));
        }
        return result;
    }
};

int main(){
    Solution s;
    string str;
    while(cin>>str){
        vector<string> vec = s.letterCombinations(str);
        for(string ss:vec){
            cout << ss << endl;
        }
    }
    return 0;
}