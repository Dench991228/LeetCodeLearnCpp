#include <algorithm>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n==1)return k;
        else if(n==0)return 0;
        else if(n==2)return k*k;
        int dp[n];
        memset(dp, 0, n * sizeof(int));
        dp[0] = k;
        dp[1] = k * k;
        for(int i=2;i<n;i++){
            dp[i] = (dp[i-1]+dp[i-2])/k*(k-1)*k;
        }
        return dp[n-1];
    }
};