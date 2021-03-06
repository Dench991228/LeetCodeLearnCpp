#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1("");
        string s2("");
        for(vector<string>::iterator it = word1.begin(); it != word1.end(); it++){
            s1+=(*it);
        }
        for(vector<string>::iterator it = word2.begin(); it != word2.end(); it++){
            s2+=(*it);
        }
        return s1 == s2;
    }
};