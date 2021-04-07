#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto it_middle = nums.begin()+1;// 中间的迭代器
        while(it_middle!=nums.end()){
            if(*(it_middle-1) > *it_middle){
                break;
            }
            it_middle ++;
        }
        auto it_left = lower_bound(nums.begin(), it_middle, target);
        auto it_right = lower_bound(it_middle, nums.end(), target);
        if(it_left != it_middle && *it_left == target) return true;
        if(it_right != nums.end() && *it_right == target) return true;
        return false;
    }
};