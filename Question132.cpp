#include <vector>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
private:
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

public:
    int minCut(string s) {
        vector<vector<bool> > isPalindrome = calculatePalindrome(s);
        deque<int> dq;
        vector<int> num_division;//[0,i]最少分割成几个回文串
        num_division.assign(s.length(),0);
        dq.push_back(-1);//当前已经完成的部分
        while(!dq.empty()){//只要dq不是空的
            int current_end = dq.front();
            if(current_end >= (int)num_division.size())break;
            cout << current_end << endl;
            dq.pop_front();
            for(int i=current_end+1;current_end+1<s.length()&&i<isPalindrome[current_end+1].size();i++){//加上一个[current_end+1, i]的回文串
                if(isPalindrome[current_end+1][i]){
                    cout << "from " << current_end+1 << " to " << i << " is a palindrom" << endl;
                    if(num_division[i]==0||(current_end>=0?num_division[current_end]:0)+1<num_division[i]){
                        num_division[i] = (current_end>=0?num_division[current_end]:0) + 1;
                        dq.push_back(i);
                    }
                }
            }
        }
        for(int i:num_division){
            cout << i << " ";
        }
        cout << endl;
        return num_division[s.length()-1]-1;
    }
};

int main(){
    string str;
    cin >> str;
    Solution s;
    int r = s.minCut(str);
    cout << "result is " << r << endl;
    return 0;
}