#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        //以A[m]和B[n]结尾的部分为尾部的最长的子数组
        //对于dp[i][j]：
        //如果A[i]!=B[j]，dp[i][j]=0
        //否则，dp[i][j] = dp[i-1][j-1]+1
        //扩展dp[i+1][j]和dp[i][j+1]
        int dp[m][n];
        memset(dp, 0, sizeof(int) * m * n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i]==B[j]){
                    dp[i][j] = 1;
                    if(i-1>=0&&j-1>=0){
                        dp[i][j]+=dp[i-1][j-1];
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int max_num = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                max_num = max(dp[i][j], max_num);
            }
        }
        return max_num;
    }
};