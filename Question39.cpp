#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        tryDp(&result, &candidates, &current, target, candidates.size()-1);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return result;
    }
private:
    /**
     * 尝试在candidate里面找出若干个数，使它们的和是target，而且这些数中最大的是candidates[index]
     * @param result 存放结果的vector
     * @param candidates 候选数
     * @param current 当前已经找出来的数
     * @param target 目标和
     * @param index 最大数的下标
    */
    void tryDp(vector<vector<int> > *result, vector<int> *candidates, vector<int> *current, int target, int index){
        if(index<0)return;
        if(target == 0){
            (*result).push_back(*current);
            return;
        }else{
            if(target >= (*candidates)[index]){//接下来的dp最大的数是candidate[index]的情况
                (*current).push_back((*candidates)[index]);
                tryDp(result, candidates, current, target-(*candidates)[index], index);
                (*current).pop_back();
            }
            tryDp(result, candidates, current, target, index-1);
        }
    }
};

void test_func(vector<int> &test){
    test.push_back(10);
}
int main(){
    vector<int> test_vec;
    test_vec.push_back(1);
    for(int i: test_vec){
        cout << i << endl;
    }
    test_func(test_vec);
    for(int i: test_vec){
        cout << i << endl;
    }
    return 0;
}