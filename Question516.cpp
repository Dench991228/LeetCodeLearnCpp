#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length()==1)return 1;
        else if(s.length()==0)return 0;
        int len = s.length();
        // dp[i][j]表示s的[i,j]部分最长的回文串序列
        // dp[i][j]: 如果s[i] == s[j]，dp[i][j] = max(dp[i+1][j-1] + 2, dp[i+1][j], dp[i][j-1])
        int dp[len][len];
        memset(dp, 0, sizeof(int) * len * len);
        //进行初始化，dp[i][i] = 1
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
        }
        //从右下角开始进行dp
        //从下往上，从左往右
        for(int row = len-2; row >= 0; row--){
            for(int col = row + 1; col<len;col++){
                dp[row][col] = max(dp[row][col-1], dp[row+1][col]);
                if(s[row] == s[col]){//二者相等
                    dp[row][col] = max(dp[row][col], dp[row+1][col-1]+2);
                }
            }
        }
        return dp[0][len-1];
    }
};