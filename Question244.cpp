#include <vector>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

class WordDistance {
private:
    unordered_map<string, list<int>> appear_list = unordered_map<string, list<int> >();
    int min_diff(list<int> &word_appear){
        list<int>::iterator it1 = word_appear.begin(), it2 = word_appear.begin();
        it2++;
        int result = 100000;
        while(it2!=word_appear.end()){
            result = min(result, *it2-*it1);
            it1++;
            it2++;
        }
        return result;
    }
    int min_diff(list<int> &word1_appear, list<int> &word2_appear){
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
public:
    WordDistance(vector<string>& wordsDict) {
        size_t i;
        for(i = 0; i < wordsDict.size(); i++){
            if(appear_list.find(wordsDict[i])==appear_list.end()){
                appear_list[wordsDict[i]] = list<int>();
            }
            appear_list[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        if(word1!=word2)return min_diff(appear_list[word1], appear_list[word2]);
        else{
            return min_diff(appear_list[word1]);
        }
    }
};