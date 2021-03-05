#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = nums[0];
        int len = nums.size();
        for(int i=1;i<len;i++){
            if(nums[i]==cur)return cur;
            cur = nums[i];
        }
        return 0;
    }
};