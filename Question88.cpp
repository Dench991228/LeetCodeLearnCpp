#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it1 = nums1.rbegin() + n;
        auto it2 = nums2.rbegin();
        auto it = nums1.rbegin();
        while(it != nums1.rend()){
            if(it1!=nums1.rend() && it2 != nums2.rend() && (*it1)> (*it2)){
                (*it) = (*it1);
                it1 --;
            }else if(it2 != nums2.rend() && it1 != nums1.rend() && (*it2) >= (*it1)){
                (*it) = (*it2);
                it2 --;
            }else{
                if(it1 != nums1.rend()){
                    (*it) = (*it1);
                    it1 --;
                }else{
                    (*it) = (*it2);
                    it2 --;
                }
            }
            it ++;
        }
    }
};