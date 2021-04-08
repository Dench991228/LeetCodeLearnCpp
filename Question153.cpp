#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size(), mid = (left + right)/2;
        int sign = nums[0];
        if(nums[right-1]>=nums[0])return nums[0];
        while(right > left){
            if(nums[mid] > sign){
                left = mid + 1;
            }else{
                right = mid;
            }
            mid = (left+right)/2;
        }
        return nums[left];
    }
};