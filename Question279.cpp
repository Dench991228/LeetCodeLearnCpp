#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
private:
    int number[100];
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp, 0x7f, sizeof(int)*(n+1));
        dp[0] = 0;
        for(int i=1;i<=100;i++){
            number[i-1] = i*i;
        }
        /*遍历可能的完全平方数*/
        for(int interval:number){
            for(int i = 1;i<=n;i++){
                if(dp[i-interval]!=0x7f7f7f7f){
                    dp[i] = min(dp[i-interval] + 1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};
int main(){
    return 0;
}