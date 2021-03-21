#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];//dp[i][j]表示有i个0和j个1的时候，最多有几个字符串
        memset(dp, 0, sizeof(int) * (m+1) * (n+1));
        int cur = 0;
        for(cur=0;cur<strs.size();cur++){
            int num_one = 0, num_zero = 0;
            for(char c:strs[cur]){
                if(c=='1')num_one ++;
                else num_zero ++;
            }
            if(num_zero<m+1&&num_one<n+1){
                dp[num_zero][num_one] = max(dp[num_zero][num_one], 1);
            }
            for(int i=num_zero;i<m+1;i++){
                for(int j=num_one;j<n+1;j++){
                    if(i-num_zero>=0&&j-num_one>=0&&dp[i-num_zero][j-num_one]!=0){
                        dp[i][j] = max(dp[i][j], dp[i-num_zero][j-num_one]+1);
                    }
                }
            }
        }
        int max_num = 0;
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                max_num = max(dp[i][j], max_num);
            }
        }
        return max_num;
    }
};