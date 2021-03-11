#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        list<int> word1_appear;
        list<int> word2_appear;
        size_t i;
        /*找出两个单词出现的频率*/
        for(i = 0;i < wordsDict.size(); i++){
            if(wordsDict[i] == word1){
                word1_appear.push_back(i);
            }
            if(wordsDict[i] == word2){
                word2_appear.push_back(i);
            }
        }
        /*开始比较*/
        list<int>::iterator it1 = word1_appear.begin();
        list<int>::iterator it2 = word2_appear.begin();
        int min_dist = 100000;
        while(it1 != word1_appear.end() && it2 != word2_appear.end()){
            min_dist = min(min_dist, abs(*it1-*it2));
            if(*it1>*it2){
                it2++;
            }
            else{
                *it1++;
            }
        }
        return min_dist;
    }
};