#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int mid = citations.size()/2;
        int left = 0, right = citations.size();
        while(left < right){
            if(citations[mid] == citations.size() - mid){//提前结束
                return citations[mid];
            }
            else if(citations[mid] > citations.size() - mid){//引用量比较大，左移，合法情况
                right = mid;
            }else{//引用量比较小，右移
                left = mid+1;
            }
            mid = (left+right)/2;
        }
        return (int)citations.size() - left;
    }
};