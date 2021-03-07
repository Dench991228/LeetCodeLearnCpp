#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int singleNumber(vector<int>& nums) {
        int current = 0;
        for(int i: nums){
            current ^= i;
        }
        return current;
    }
};