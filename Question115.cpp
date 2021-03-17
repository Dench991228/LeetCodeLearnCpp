#include <vector>
#include <string>
#include <deque>

using namespace std;
class state{
public:
    int s_end, t_end;
    state(int s, int t):s_end(s), t_end(t){}
};
class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length()==0)return 1;
        else if(s.length()<t.length())return 0;
        int m = s.length();//s的长度
        int n = t.length();//t的长度
        /*dp[i][j]表示的是s匹配到i，t匹配到j的时候，一共有多少种可能性*/
        /*dp[i][j] = dp[i-1][j-1] + dp[i-1][j]*/
        long dp[m+1][n+1];
        bool visited[m+1][n+1];
        memset(dp ,0, sizeof(long)*(m+1)*(n+1));
        state start(0, 0);
        deque<state> queue;
        queue.push_back(start);
        dp[0][0] = 1;
        while(!queue.empty()){
            state current = queue.front();
            queue.pop_front();
            if(current.s_end == m)continue;
            if(s[current.s_end]==t[current.t_end]){//如果当前的两个字符能够匹配上
                state new_state(current.s_end+1, current.t_end+1);
                if(dp[current.s_end+1][current.t_end+1]==0)queue.push_back(new_state);
                dp[current.s_end+1][current.t_end+1] += dp[current.s_end][current.t_end];
            }
            if(current.s_end+1<=m){
                state new_state(current.s_end+1, current.t_end);
                if(dp[current.s_end+1][current.t_end]==0)queue.push_back(new_state);
                dp[current.s_end+1][current.t_end] += dp[current.s_end][current.t_end];
            }
        }
        return dp[m][n];
    }
};