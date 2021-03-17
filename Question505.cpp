#include <vector>
#include <list>
#include <iostream>

using namespace std;

class state{
public:
    int former_direction;
    int steps;
    int pos_r;
    int pos_c;
    state(int x, int y, int d, int s):pos_r(x), pos_c(y), former_direction(d), steps(s){}
    static state move_left(state s,vector<vector<int> >&maze){
        int c = s.pos_c;
        int distance = s.steps;
        while(c-1>=0&&maze[s.pos_r][c-1]==0){
            c--;
            distance++;
        }
        return state(s.pos_r, c, 3, distance);
    }
    static state move_right(state s, vector<vector<int> >&maze){
        int c = s.pos_c;
        int distance = s.steps;
        while(c+1<maze[0].size()&&maze[s.pos_r][c+1]==0){
            c++;
            distance++;
        }
        return state(s.pos_r, c, 1, distance);
    }
    static state move_up(state s,vector<vector<int> >&maze){
        int r = s.pos_r;
        int distance = s.steps;
        while(r-1>=0&&maze[r-1][s.pos_c]==0){
            r--;
            distance ++;
        }
        return state(r, s.pos_c, 0, distance);
    }
    static state move_down(state s,vector<vector<int> >&maze){
        int r = s.pos_r;
        int distance = s.steps;
        while(r+1<maze.size()&&maze[r+1][s.pos_c]==0){
            r++;
            distance++;
        }
        return state(r, s.pos_c, 2, distance);
    }
    state (*f[4])(state,vector<vector<int> > &) = {move_up, move_right, move_down, move_left};
};
class Solution {
private:
    bool stopped(state s, vector<vector<int> > &maze){
        switch(s.former_direction){
            case 2:
                return s.pos_r-1<=0||maze[s.pos_r-1][s.pos_c]==1;
            case 0:
                return s.pos_r+1>=maze.size()||maze[s.pos_r+1][s.pos_c]==1;
            case 3:
                return s.pos_c-1<=0||maze[s.pos_r][s.pos_c-1]==1;
            case 1:
                return s.pos_c+1>=maze[0].size()||maze[s.pos_r][s.pos_c+1]==1;
        }
        return false;
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int height = maze.size();
        int width = maze[0].size();
        bool visited[height][width];
        int shortest_distance[height][width];
        memset(visited, false, sizeof(bool)*height*width);
        memset(shortest_distance, 0x7f, sizeof(int)*height*width);
        state s(start[0], start[1], -1, 0);
        visited[start[0]][start[1]] = true;
        list<state> queue;
        queue.push_back(s);
        shortest_distance[start[0]][start[1]] = 0;
        while(!queue.empty()){
            state current_state = queue.front();
            //cout << current_state.pos_r << " " << current_state.pos_c << " " << current_state.steps << endl;
            queue.pop_front();
            for(int d = 0;d<4;d++){
                if(d!=current_state.former_direction){
                    state expand = current_state.f[d](current_state,maze);
                    if(shortest_distance[expand.pos_r][expand.pos_c]>expand.steps){//更新它的距离，从新放到队列中
                        shortest_distance[expand.pos_r][expand.pos_c] = expand.steps;
                        queue.push_back(state(expand.pos_r, expand.pos_c, expand.former_direction, expand.steps));
                    }
                }  
            } 
        }
        int result = shortest_distance[destination[0]][destination[1]]==0x7f7f7f7f?-1:shortest_distance[destination[0]][destination[1]];
        return result;
    }
};