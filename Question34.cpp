#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 返回数组中第一个大于x的数的下标，注意，数组中必须要有大于x的数
    */
    int upper_bound(vector<int> &nums, int x){
        int left = 0, right = nums.size()-1;
        int mid = left + (right - left) / 2;
        cout << left << "," << mid << "," << right << endl;
        while(left < right){
            if(nums[mid] <= x){
                left = mid + 1;
            }else{
                right = mid;
            }
            mid = left + (right - left) / 2;
            cout << left << "," << mid << "," << right << endl;
        }
        return right;
    }
    /**
     * 返回数组中第一个大于等于x的数的下标，注意，数组中必须要有大于等于x的数
    */
    int lower_bound(vector<int> &nums, int x){
        int left = 0, right = nums.size()-1;
        int mid = left + (right - left) / 2;
        cout << left << "," << mid << "," << right << endl;
        while(left < right){
            if(nums[mid] < x){
                left = mid + 1;
            }else{
                right = mid;
            }
            mid = left + (right - left) / 2;
            cout << left << "," << mid << "," << right << endl;
        }
        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()==0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else if(target>*nums.rbegin()){//最后一个数没有x大，直接GG
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }else if(target == *nums.rbegin()){//最后一个数和x一样大，只用考虑开头
            result.push_back(lower_bound(nums, target));
            result.push_back(nums.size()-1);
            return result;
        }else{//最后一个数比x小，正常处理
            int pos_first_ge = lower_bound(nums, target);
            int pos_first_gt = upper_bound(nums, target);
            if(pos_first_ge == pos_first_gt){
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }else{
                result.push_back(pos_first_ge);
                result.push_back(pos_first_gt-1);
                return result;
            }
        }
    }
};

int main(){
    int i;
    vector<int> vec;
    int x;
    cin >> x;
    while(cin >> i){
        vec.push_back(i);
    }
    Solution s;
    cout << s.upper_bound(vec, x);
    cout << endl;
    cout << s.lower_bound(vec, x);
    return 0;
}