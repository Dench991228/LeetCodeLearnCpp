//
// Created by 邓涵之 on 2021/3/31.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool vecCmp(const int t, const vector<int> &vec){
        return t < vec[0];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto follow_line = upper_bound(matrix.begin(), matrix.end(), target, vecCmp);
        if(follow_line == matrix.begin())return false;
        else{
            return binary_search((*follow_line--).begin(), (*follow_line--).end(), target);
        }
    }
};