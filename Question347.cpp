#include <vector>
#include <map>
#include <queue>

using namespace std;
class item{
private:
    int number;
    int appearance;
public:
    item(int n, int a):number(n), appearance(a){}
    bool operator < (const item &i)const{
        if(this -> appearance < i.appearance){
            return true;
        }else{
            return false;
        }
    }
    int getNumber(){
        return number;
    }
};
class Solution {
public:
    /**
     * 统计nums中出现频率前k高的元素
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frequency;
        vector<int> result;
        priority_queue<item> pq;
        for(int i:nums){
            map<int,int>::iterator it = frequency.find(i);
            if(it == frequency.end()){
                frequency.insert(pair<int,int>(i,1));
            }else{
                (*it).second++;
            }
        }
        for(pair<int,int> p:frequency){
            item i(p.first, p.second);
            pq.push(i);
        }
        for(int i=0;i<k;i++){
            item it = pq.top();
            result.push_back(it.getNumber());
            pq.pop();
        }
        return result;
    }
};

int main(){
    vector<int> myVec = {1,1,1,2,2,3};
    Solution s;
    s.topKFrequent(myVec, 1);
    return 0;
}