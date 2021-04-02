//
// Created by 邓涵之 on 2021/3/31.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    /**
     * 保证target各位小于等于mother的各位，给target最后一位加一，如果超过就进位
     * */
    void vector_add(vector<int>& mother, vector<int>& target){
        auto target_it = target.rbegin();
        auto mother_it = mother.rbegin();
        while(target_it != target.rend() && mother_it != mother.rend()){
            if(*target_it != *mother_it){// 不进位
                (*target_it)++;
                break;
            }else{// 进位
                (*target_it) = 0;
            }
            target_it ++;
            mother_it ++;
        }
    }
    /**
     * 根据frequency从numbers里面拿出对应数量的数字出来，并且返回一个vector
     * */
    vector<int> getResult(vector<int>& numbers, vector<int>& frequent){
        vector<int> result;
        auto numbers_it = numbers.begin();
        auto frequent_it = frequent.begin();
        while(numbers_it != numbers.end() && frequent_it != frequent.end()){
            if(*frequent_it != 0){
                for(int i=0;i<(*frequent_it);i++){
                    result.push_back(*numbers_it);
                }
            }
            numbers_it ++;
            frequent_it ++;
        }
        return result;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 统计每个数出现了几次
        vector<int> numbers;// 各个数字
        vector<int> frequent;// 各个数字在母集合中出现的频率
        map<int, int> stat;
        for(int i:nums){
            stat[i] ++;
        }
        for(pair<int,int> p:stat){
            numbers.push_back(p.first);
            frequent.push_back(p.second);
        }
        // 整理之前的统计结果
        vector<vector<int>> result;
        vector<int> current_subset(numbers.size());// 当前子集中的出现频率
        while(current_subset < frequent){
            vector_add(frequent, current_subset);
            result.push_back(getResult(numbers, current_subset));
            for(int i:current_subset){
                cout << i << " ";
            }
            cout << endl;
        }
        return result;
    }
};
