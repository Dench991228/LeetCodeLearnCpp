#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > str_palin;
    vector<string> current;
    vector<vector<string> > result;
    /**
     * 判断一个字符串中任意一个[i,j]是不是回文串
    */
    vector<vector<bool> >  calculatePalindrome(string str){
        vector<vector<bool> > result;
        int len = str.length();
        result.assign(len, vector<bool>(len));
        for(int interval = 0; interval<len;interval++){
            for(int i=0;i<len-interval;i++){//计算[i,i+interval]是不是回文串
                if(interval<=1)result[i][i+interval] = (str[i]==str[i+interval]);
                else{
                    result[i][i+interval] = (str[i]==str[i+interval])&&(result[i+1][i+interval-1]);
                }
            }
        }
        return result;
    }
    void dfs(string str, vector<vector<bool> > isPalindrome, int s){
        int len = str.length();
        if(s==len){
            result.push_back(current);
        }
        for(int i=s;i<len;i++){
            if(isPalindrome[s][i]){
                current.push_back(str.substr(s,i-s+1));
                dfs(str, isPalindrome, i+1);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string> > partition(string s) {
        vector<vector<bool> > palinVec = calculatePalindrome(s);
        dfs(s, palinVec, 0);
        return result;
    }
};

int main(){
    string test_str;
    cin >> test_str;
    Solution s;
    vector<vector<bool> >result = s.calculatePalindrome(test_str);
    for(vector<bool> row:result){
        for(bool b:row){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}