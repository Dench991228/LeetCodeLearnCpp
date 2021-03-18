#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, 0x7f, sizeof(int)*(amount+1));
        dp[0] = 0;
        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                dp[i] = min(dp[i-coin]+1, dp[i]);
            }
        }
        return dp[amount]==0x7f7f7f7f?-1:dp[amount];
    }
};