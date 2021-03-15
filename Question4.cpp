#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    /**
     * 找到两个数组之间的第k小的数字
    */
    int getKthMinimal(vector<int> &nums1,vector<int> &nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;//两个数组的[0, index)被确认属于前k个
        while(true){
            if(index1 == m){
                return nums2[index2+k-1];
            }
            if(index2 == n){
                return nums1[index1+k-1];
            }
            if(k==1){
                return min(nums1[0], nums2[0]);
            }

            int newIndex1 = min(index1+k/2-1, m-1);
            int newIndex2 = min(index2+k/2-1, n-1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if(pivot1<=pivot2){//pivot1比pivot2小，所以可以确定前面的都属于k中的数了
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }else{
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
public:
    /**
     * 找到两个数组的中位数，采用不断二分的方式进行
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*先排除某个数组一个都不要的情况*/
        int total_length = nums1.size() + nums2.size();
        if(total_length%2==0){
            return (1.0*getKthMinimal(nums1, nums2, total_length/2)+getKthMinimal(nums1, nums2, total_length/2+1))/2.0;
        }else{
            return getKthMinimal(nums1, nums2, (total_length+1)/2);
        }
    }
};