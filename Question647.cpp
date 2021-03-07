#include <vector>
#include <string>

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
    int countSubstrings(string s) {
        vector<vector<bool> > palinVec = calculatePalindrome(s);
        int result = 0;
        for(vector<bool> row: palinVec){
            for(bool b:row){
                if(b)result++;
            }
        }
        return result;
    }
};