#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = x<0;
        long temp = x;
        if(temp<0)temp=-temp;
        long sum = 0;
        while(temp!=0){
            sum *= 10;
            sum += temp % 10;
            temp/=10;
        }
        if(flag)sum*=(-1);
        if(sum<=(int)0x80000000)return 0;
        else if(sum>=0x7fffffff)return 0;
        return sum;
    }
};

int main(){
    int n;
    Solution s;
    cout << (int)(0x80000000) << endl;
    cout << 0x7fffffff << endl;
    while(cin >> n){
        s.reverse(n);
    }
    return 0;
}