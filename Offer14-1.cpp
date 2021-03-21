#include <algorithm>

using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        int dp[n+1];
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = i-1;
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i], j*(i-j));
                dp[i] = max(dp[i], j*dp[i-j]);
            }
        }
        return dp[n];
    }
};