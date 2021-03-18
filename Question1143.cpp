#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int dp[m+1][n+1];//dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1)
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[i] == text2[j])dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }   
        }
        return dp[m][n];
    }
};