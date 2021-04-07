#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current_number = nums[0];
        int current_repeat = 1;
        auto it_fast = nums.begin() + 1;
        auto it_slow = nums.begin();
        int total = 1;
        while(it_fast != nums.end()){
            if(*it_fast != current_number){
                current_number = *it_fast;
                current_repeat = 1;
                it_slow ++;
                (*it_slow) = *it_fast;
                total ++;
            }else{
                current_repeat ++;
                if(current_repeat <= 2){
                    it_slow ++;
                    (*it_slow) = (*it_fast);
                    total ++;
                }
            }
        }
        return total;
    }
};