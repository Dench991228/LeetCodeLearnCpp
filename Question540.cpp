#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        int mid = left + (right - left)/2;
        cout << "(" << left << "," << mid << "," << right << ")" <<endl;
        while(left < right){
            if(mid==0)return nums[mid];
            if(mid==nums.size()-1)return nums[mid];
            if(mid%2==0){//mid是偶数，如果前面的和mid不一样，那么前面的（不含mid）都没问题
                if(nums[mid-1]!=nums[mid]){
                    if(nums[mid+1]!=nums[mid])return nums[mid];
                    left = mid+1;
                }else{
                    right = mid - 1;
                }
            }else{//mid是奇数，如果后面一个元素不等于nums[mid]，就表明前面(包括mid)都没问题
                if(nums[mid+1]!=nums[mid]){
                    if(nums[mid-1]!=nums[mid])return nums[mid];
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            mid = left + (right - left)/2;
            cout << "(" << left << "," << mid << "," << right << ")" <<endl;
        }
        return nums[left];
    }
};