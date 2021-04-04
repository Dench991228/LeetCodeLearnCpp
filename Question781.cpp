#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        int result = 0;
        for(int i:answers){
            map[i] ++;
        }
        for(pair<int,int> p:map){
            result += p.second;
            result += (p.second % (p.first+1) == 0)?0:p.second - p.second%(p.first+1);
        }
        return result;
    }
};