#include <algorithm>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int mod = 1e9+7;
        int dp[n+1];
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            long current_max = 0;
            for(int j=1;j<i;j++){
                current_max = max(current_max, (long)j*(long)(i-j));
                current_max = max(current_max, (long)j*(long)dp[i-j]);
            }
            dp[i] = current_max%mod;
        }
        return dp[n];
    }
};