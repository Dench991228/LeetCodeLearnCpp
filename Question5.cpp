#include <vector>
#include <string>
#include <algorithm>
#include <list>

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
    string longestPalindrome(string s) {
        vector<vector<bool> > isPalindrom = calculatePalindrome(s);
        int len = s.length();
        int max_len = 0;
        int start;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(isPalindrom[i][j]){
                    if(j-i+1>max_len){
                        start = i;
                        max_len = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start,max_len);
    }
};