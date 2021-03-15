#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> stone_map;//记录石头位置-下标的映射
        int last_stone = stones.back();//最后的石头，标记边界
        int current_index = 0;
        for(int s:stones){
            stone_map[s] = current_index;
            current_index++;
        }
        bool visited[stones.size()][stones.size()*2+10];//visited[i][j]表明已经有跳到第i块石头且最后一跳跳了j格
        memset(visited, 0,(stones.size()*stones.size()*2+10)*sizeof(bool));
        deque<int> stone_position;//最后一跳石头的位置，不是stone_map里面的下标
        deque<int> last_jump;//上一跳的距离
        stone_position.push_back(0);
        last_jump.push_back(0);
        while(!stone_position.empty()&&!last_jump.empty()){
            int former_jump = last_jump.front();//上一跳距离
            last_jump.pop_front();
            int current_position = stone_position.front();//现在在哪
            stone_position.pop_front();
            //跳k+1步
            if(current_position+former_jump+1==last_stone){//看看多跳一步能不能一次到位
                return true;
            }
            else if(stone_map.find(current_position+former_jump+1) != stone_map.end()){//下一跳可以到石头上
                int next_index = (*stone_map.find(current_position+former_jump+1)).second;//下一跳的下标
                if(!visited[next_index][former_jump+1]){
                    visited[next_index][former_jump+1] = true;
                    stone_position.push_back(current_position+former_jump+1);
                    last_jump.push_back(former_jump+1);
                }
            }
            //跳k步
            if(former_jump!=0&&current_position+former_jump==last_stone){//看看多跳一步能不能一次到位
                return true;
            }
            else if(former_jump!=0&&stone_map.find(current_position+former_jump) != stone_map.end()){//下一跳可以到石头上
                int next_index = (*stone_map.find(current_position+former_jump)).second;//下一跳的下标
                if(!visited[next_index][former_jump]){
                    visited[next_index][former_jump] = true;
                    stone_position.push_back(current_position+former_jump);
                    last_jump.push_back(former_jump);
                }
            }
            //跳k-1步
            if(former_jump-1>0 && current_position+former_jump-1==last_stone){//看看多跳一步能不能一次到位
                return true;
            }
            else if(former_jump-1>0 && stone_map.find(current_position+former_jump-1) != stone_map.end()){//下一跳可以到石头上
                int next_index = (*stone_map.find(current_position+former_jump-1)).second;//下一跳的下标
                if(!visited[next_index][former_jump-1]){
                    visited[next_index][former_jump-1] = true;
                    stone_position.push_back(current_position+former_jump-1);
                    last_jump.push_back(former_jump-1);
                }
            }
        }
        return false;
    }
};