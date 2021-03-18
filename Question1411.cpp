#include <iostream>

using namespace std;

bool isConflict(char a, char b){
    if(((a%4)&(b%4))==a%4&&((a%4)&(b%4))==b%4){
        return true;
    }
    a>>=2;
    b>>=2;
    if(((a%4)&(b%4))==a%4&&((a%4)&(b%4))==b%4){
        return true;
    }
    a>>=2;
    b>>=2;
    if(((a%4)&(b%4))==a%4&&((a%4)&(b%4))==b%4){
        return true;
    }
    return false;
}

class Solution {
public:
    int numOfWays(int n) {
        if(n==1)return 12;
        char basic[12] = {0b000100, 0b001100, 0b010001, 0b011101, 0b110011, 0b110111, 0b001101, 0b011100, 0b000111, 0b110100, 0b010011, 0b110001};
        int mod = 1000000007;
        int dp[5001][12];//dp[i][j]表示弄了i排，最后一排是basic[j]的状态数
        memset(dp, 0, sizeof(int)*5001*12);
        for(int i=0;i<12;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<12;j++){
                for(int k=0;k<12;k++){
                    if(!isConflict(basic[j], basic[k])){
                        dp[i][j] += dp[i-1][k]%mod;
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        int sum = 0;
        for(int i:dp[n]){
            sum += i%mod;
            sum %=mod;
        }
        return sum;
    }
};
int main(){
    Solution s;
    s.numOfWays(0);
    return 0;
}