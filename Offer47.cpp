#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int height = grid.size();
        if(height==0)return 0;
        int width = grid[0].size();
        if(width==0)return 0;
        int dp[height][width];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];

        /*初始化第一行*/
        for(int i=1;i<width;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        /*初始化第二行*/
        for(int i=1;i<height;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1;i<height;i++){
            for(int j=1;j<width;j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[height-1][width-1];
    }
};