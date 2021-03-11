#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        /*先找出父节点的下标*/
        int father_sub = 0;
        while(father_sub < ppid.size()){
            if(ppid[father_sub] == 0){
                break;
            }
            father_sub ++;
        }
        int father_pid = pid[father_sub];
        /*开始统计父子关系*/
        unordered_map<int, list<int> > ppid_pid;//pid和它的子进程 
        vector<int>::iterator ppid_iter = ppid.begin(), pid_iter = pid.begin();
        while(ppid_iter != ppid.end() && pid_iter != pid.end()){
            if(ppid_pid.find(*ppid_iter) == ppid_pid.end()){//这个父节点的子进程队列还没被建立
                ppid_pid[*ppid_iter] = list<int>();
            }
            ppid_pid[*ppid_iter].push_back(*pid_iter);
            ppid_iter ++;
            pid_iter ++;
        }
        /*开始进行遍历*/
        list<int> pids;//等待被访问的节点
        list<bool> killed;//这个节点被杀死了吗
        vector<int> result;
        killed.push_back(kill==father_pid);
        pids.push_back(father_pid);
        while(!pids.empty()){
            int cur_pid = pids.front();
            bool this_killed = killed.front();
            pids.pop_front();
            killed.pop_front();
            if(this_killed)result.push_back(cur_pid);
            for(int child_pid: ppid_pid[cur_pid]){
                pids.push_back(child_pid);
                killed.push_back(this_killed||kill == child_pid);
            }
        }
        return result;
    }
};