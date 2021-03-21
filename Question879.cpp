#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // dp[i][j][k]：考虑前i个group和profit的情况下，消耗了j员工，产生k利润的情况
        // 对于dp[i][j][k]
        //dp[i+1][j][k]+=dp[i][j][k]
        //如果j+group[i+1]>n那就GG
        //如果不GG，就考虑接下来的情况
        //如果k+profit[i+1]>minProfit，那么dp[i+1][j+group[i+1]][minProfit]+=dp[i][j][k]
        //否则，dp[i+1][j+group[i+1]][k+profit[i+1]]+=dp[i][j][k]
        int mod = 1e9+7;
        int group_num = group.size();
        int dp[group.size()][n+1][minProfit+1];
        memset(dp, 0, sizeof(int)*(n+1)*(minProfit+1)*group.size());
        /*初始化*/
        dp[0][0][0] = 1;
        if(group[0]<=n){
            if(profit[0]>minProfit){
                dp[0][group[0]][minProfit]++;
            }else{
                dp[0][group[0]][profit[0]]++;
            }
        }
        for(int j=0;j<n+1;j++){
            for(int k=0;k<minProfit+1;j++){
                cout << dp[0][j][k] << " ";
            }
            cout << endl;
        }
        for(int i=1;i<group_num;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<minProfit+1;k++){
                    if(dp[i-1][j][k]!=0){
                        dp[i][j][k] += dp[i-1][j][k];
                        if(!(j+group[i]>n)){
                            if(k+profit[i]>minProfit){
                                dp[i][j+group[i]][minProfit] += dp[i][j][k]%mod;
                                dp[i][j+group[i]][minProfit] %= mod;
                            }else{
                                dp[i][j+group[i]][k+profit[i]] += dp[i][j][k]%mod;
                                dp[i][j+group[i]][k+profit[i]] %= mod;
                            }
                        }
                    }
                }
            }
            for(int j=0;j<n+1;j++){
                for(int k=0;k<minProfit+1;j++){
                    cout << dp[i][j][k] << " ";
                }
                cout << endl;
            }
        }
        int sum = 0;
        for(int i=0;i<=n;i++){
            sum += dp[group_num-1][i][minProfit]%mod;
            sum %= mod;
        }
        return sum;
    }
};