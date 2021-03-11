#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        double current_avg = 0;
        double max_avg = -100000;
        int left = 0, right = 0;//维护[left, right)之间的数组
        for(int i=0;i<k;i++){
            current_sum += nums[right];
            right ++;
            current_avg = current_sum / (right - left);
        }
        max_avg = max(max_avg, current_avg);
        while(right < nums.size()){
            /*寻找当前的left对应的，平均数最大，长度至少为k的数组*/
            while(right < nums.size() && nums[right] > current_avg){
                current_sum += nums[right];
                right ++;
                current_avg = current_sum / (right - left);
            }
            max_avg = max(max_avg, current_avg);
            cout << "local maximum found:[" << left << "," << right << ")" << endl; 
            cout << "current_avg = " << current_avg << endl;
            current_sum -= nums[left];
            left ++;
            current_avg = current_sum / (right-left);
            /*调整到[left, right)长度为k*/
            while(right < nums.size() && right-left<k){
                current_sum += nums[right];
                right ++;
                current_avg = current_sum / (right - left);
            }
            max_avg = max(max_avg, current_avg);
        }
        return max_avg;
    }
};

int main(){
    vector<int> testee = {1,12,-5,-6,50,3};
    int k = 4;
    Solution s;
    s.findMaxAverage(testee, k);
    return 0;
}