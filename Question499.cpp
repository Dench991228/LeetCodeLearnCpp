#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class state{
public:
    int former_direction;
    int steps;
    int pos_r;
    int pos_c;
    string current_path;
    state(int x, int y, int d, int s):pos_r(x), pos_c(y), former_direction(d), steps(s){}
    static state move_left(state s,vector<vector<int> >&maze){
        int c = s.pos_c;
        int distance = s.steps;
        while(c-1>=0&&(maze[s.pos_r][c-1]==0||maze[s.pos_r][c-1]==2)&&maze[s.pos_r][c]!=2){
            c--;
            distance++;
        }
        state result = state(s.pos_r, c, 1, distance);
        result.current_path = s.current_path;
        if(distance != s.steps)result.current_path+='l';
        return result;
    }
    static state move_right(state s, vector<vector<int> >&maze){
        int c = s.pos_c;
        int distance = s.steps;
        while(c+1<maze[0].size()&&(maze[s.pos_r][c+1]==0||maze[s.pos_r][c+1]==2)&&maze[s.pos_r][c]!=2){
            c++;
            distance++;
        }
        state result = state(s.pos_r, c, 1, distance);
        result.current_path = s.current_path;
        if(distance != s.steps)result.current_path+='r';
        return result;
    }
    static state move_up(state s,vector<vector<int> >&maze){
        int r = s.pos_r;
        int distance = s.steps;
        while(r-1>=0&&(maze[r-1][s.pos_c]==0||maze[r-1][s.pos_c]==2)&&maze[r][s.pos_c]!=2){
            r--;
            distance ++;
        }
        state result = state(r, s.pos_c, 2, distance);
        result.current_path = s.current_path;
        if(distance != s.steps)result.current_path+='u';
        return result;
    }
    static state move_down(state s,vector<vector<int> >&maze){
        int r = s.pos_r;
        int distance = s.steps;
        while(r+1<maze.size()&&(maze[r+1][s.pos_c]==0||maze[r+1][s.pos_c]==2)&&maze[r][s.pos_c]!=2){
            r++;
            distance++;
        }
        state result = state(r, s.pos_c, 2, distance);
        result.current_path = s.current_path;
        if(distance != s.steps)result.current_path+='d';
        return result;
    }
    state (*f[4])(state,vector<vector<int> > &) = {move_up, move_right, move_down, move_left};
};
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& hole) {
        int height = maze.size();
        int width = maze[0].size();
        maze[hole[0]][hole[1]] = 2;
        int shortest_distance[height][width];
        memset(shortest_distance, 0x7f, sizeof(int)*height*width);
        state s(start[0], start[1], -1, 0);
        list<state> queue;
        queue.push_back(s);
        shortest_distance[start[0]][start[1]] = 0;
        //string result;//最终用来返回的字符串
        string paths[height][width];
        while(!queue.empty()){
            state current_state = queue.front();
            //cout << current_state.pos_r << " " << current_state.pos_c << " " << current_state.steps << endl;
            queue.pop_front();
            for(int d = 0;d<4;d++){
                if(d!=current_state.former_direction){
                    state expand = current_state.f[d](current_state,maze);
                    if(shortest_distance[expand.pos_r][expand.pos_c]>expand.steps){//距离更短，强制更新
                        shortest_distance[expand.pos_r][expand.pos_c] = expand.steps;
                        paths[expand.pos_r][expand.pos_c] = expand.current_path;
                        queue.push_back(expand);
                    }else if(shortest_distance[expand.pos_r][expand.pos_c]==expand.steps&&paths[expand.pos_r][expand.pos_c]>expand.current_path){//距离相同，字典序更小
                        paths[expand.pos_r][expand.pos_c] = expand.current_path;
                        queue.push_back(expand);
                    }   
                }  
            } 
        }
        return paths[hole[0]][hole[1]].length()==0?"impossible":paths[hole[0]][hole[1]];
    }
};