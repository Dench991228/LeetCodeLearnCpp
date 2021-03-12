#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int num_houses = costs.size();
        if(num_houses==0)return 0;
        int num_colors = costs[0].size();
        if(num_colors==0)return 0;
        int dp[num_houses][num_colors];
        int min_val[num_houses];//最小值的数组
        int min_pos[num_houses];//最小值的颜色
        int second_min_val[num_houses];//第二小的值的数组
        int second_min_pos[num_houses];//第二小的值的颜色
        memset(dp, 0, num_houses * num_colors * sizeof(int));
        min_val[0] = 1<<30;
        for(int i=0;i<num_colors;i++){
            dp[0][i] = costs[0][i];
        }
        /*找最小*/
        int current_min = 1 << 30;
        for(int i=0;i<num_colors;i++){
            if(dp[0][i]<current_min){
                min_val[0] = dp[0][i];
                min_pos[0] = i;
                current_min = dp[0][i];
            }
        }
        /*找第二小*/
        current_min = 1 << 30;
        for(int i=0;i<num_colors;i++){
            if(dp[0][i]<current_min&&i!=min_pos[0]){
                second_min_val[0] = dp[0][i];
                second_min_pos[0] = i;
                current_min = dp[0][i];
            }
        }
        for(int i=1;i<num_houses;i++){
            min_val[i] = 1<<30;
            for(int j=0;j<num_colors;j++){
                if(j==min_pos[i-1]){//上一个在这里最小
                    dp[i][j] = second_min_val[i-1] + costs[i][j];
                }else{
                    dp[i][j] = min_val[i-1] + costs[i][j];
                }
            }
            int current_min = 1 << 30;
            /*找最小*/
            for(int j=0;j<num_colors;j++){
                if(dp[i][j]<current_min){
                    min_val[i] = dp[i][j];
                    min_pos[i] = j;
                    current_min = dp[i][j];
                }
            }
            /*找第二小*/
            current_min = 1 << 30;
            for(int j=0;j<num_colors;j++){
                if(dp[i][j]<current_min&&j!=min_pos[i]){
                    second_min_val[i] = dp[i][j];
                    second_min_pos[i] = j;
                    current_min = dp[i][j];
                }
            }
        }
        /*展现dp*/
        for(auto &arr: dp){
            for(int i:arr){
                cout << i << " ";
            }
            cout << endl;
        }
        /*展现四个小数组*/
        for(int i:min_val){
            cout << i << " ";
        }
        cout << endl;
        for(int i:min_pos){
            cout << i << " ";
        }
        cout << endl;
        for(int i:second_min_val){
            cout << i << " ";
        }
        cout << endl;
        for(int i:second_min_pos){
            cout << i << " ";
        }
        cout << endl;
        return min_val[num_houses-1];
    }
};