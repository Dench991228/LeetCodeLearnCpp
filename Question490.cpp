#include <vector>
#include <list>
#include <iostream>

using namespace std;

class state{
public:
    int former_direction;
    int pos_r;
    int pos_c;
    state(int x, int y, int d):pos_r(x), pos_c(y), former_direction(d){}
    static state move_left(state s,vector<vector<int> >&maze){
        cout << "left" << endl;
        int c = s.pos_c;
        while(c>=0&&maze[s.pos_r][c]==0){
            c--;
        }
        c++;
        return state(s.pos_r, c, 3);
    }
    static state move_right(state s, vector<vector<int> >&maze){
        cout << "right" << endl;
        int c = s.pos_c;
        while(c<maze[0].size()&&maze[s.pos_r][c]==0){
            c++;
        }
        c--;
        return state(s.pos_r, c, 1);
    }
    static state move_up(state s,vector<vector<int> >&maze){
        cout << "up" << endl;
        int r = s.pos_r;
        while(r>=0&&maze[r][s.pos_c]==0){
            r--;
        }
        r++;
        return state(r, s.pos_c, 0);
    }
    static state move_down(state s,vector<vector<int> >&maze){
        cout << "down" << endl;
        int r = s.pos_r;
        while(r<maze.size()&&maze[r][s.pos_c]==0){
            r++;
        }
        r--;
        return state(r, s.pos_c, 2);
    }
    state (*f[4])(state,vector<vector<int> > &) = {move_up, move_right, move_down, move_left};
};
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int height = maze.size();
        int width = maze[0].size();
        bool visited[height][width];
        memset(visited, false, sizeof(bool)*height*width);
        state s(start[0], start[1], -1);
        visited[start[0]][start[1]] = true;
        list<state> queue;
        queue.push_back(s);
        while(!queue.empty()){
            state current_state = queue.front();
            queue.pop_front();
            //找到终点了
            if(current_state.pos_r==destination[0]&&current_state.pos_c==destination[1]){
                return true;
            }
            for(int d = 0;d<4;d++){
                if(d!=current_state.former_direction){
                    state expand = current_state.f[d](current_state,maze);
                    if(!visited[expand.pos_r][expand.pos_c]){
                        queue.push_back(expand);
                        visited[expand.pos_r][expand.pos_c] = true;
                    }
                }  
            } 
        }
        return false;
    }
};