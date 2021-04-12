#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sequence;
        for(int i:nums){
            sequence.push_back(to_string(i));
        }
        sort(sequence.begin(), sequence.end(), [](const string &a, const string &b){
            int i = 0, j = 0;
            int len_a = a.size(), len_b = b.size();
            while(i < len_a && j < len_b){
                if(a[i] < b[i]){
                    return false;
                }else if(a[i] > b[i]){
                    return true;
                }
                i++;
                j++;
            }
            if(i == len_a && j == len_b){// 两个数一样123 1231 1231231 1231123
                return false;
            }else{
                // 一共两种可能行
                // 短字符串在前，后面是长字符串
                // 长字符串在前，后面是长字符串去掉短字符串相同的部分，加上短字符串
                if(i == len_a){// a是短字符串
                    // a 在前和 a 在后
                    return b > b.substr(len_a, len_b - len_a) + a;
                }else{// b 在前和 b 在后
                    return a < a.substr(len_b, len_a - len_b) + b;
                }
            }
        });
        string result;
        for(string s:sequence){
            result += s;
        }
        int size = result.size();
        int i;
        for(i=0;i<size;i++){
            if(result[i]!='0')break;
        }
        if(i!=size){
            return result.substr(i, size - i);
        }else{
            return string("0");
        }
    }
};