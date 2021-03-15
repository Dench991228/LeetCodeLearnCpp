#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int start, len = s.length();
        string result;
        for(start = 0; start < numRows; start++){
            int interval = (numRows-1)*2-start*2;
            int i = 0;
            while(i<len){
                if(interval!=0){
                    result+=s[start+i];
                    cout << start+i << " " << s[start+i] << endl;
                }
                i+=interval;
                interval = (numRows-1)*2-interval;
            }
        }
        return result;
    }
};
int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    Solution s;
    cout << s.convert(str,n) << endl;
    return 0;
}