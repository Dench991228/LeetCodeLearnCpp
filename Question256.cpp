#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int num_houses = costs.size();
        int num_colors = 3;
        int dp[num_houses][num_colors];
        memset(dp, 0, num_houses * num_colors * sizeof(int));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i=1;i<num_houses;i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
        }
        return min(min(dp[num_houses-1][0], dp[num_houses-1][1]), dp[num_houses-1][2]);
    }
};