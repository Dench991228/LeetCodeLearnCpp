#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    /**
     * 不断挪动nums的nums[start]，使得其左侧所有元素都小于等于，右边都比它大
    */
    int shift(vector<int> &nums, int start, int end){
        if(end-start == 1)return start;
        if(end-start == 2){
            if(nums[start] < nums[start+1]){
                return start;
            }else{
                int temp = nums[start+1];
                nums[start+1] = nums[start];
                nums[start] = temp;
                return start+1;
            }
        }
        int s = start+1;
        int e = end-1;
        //s右移，直到有比nums[0]大的，e左移，找到比nums[0]小的，然后交换
        while(s<e){
            if(!(nums[s]<=nums[start])&&!(nums[e]>nums[start])){//s指向一个比nums[0]大的数，e指向一个小于等于nums[1]
                int temp = nums[e];
                nums[e] = nums[s];
                nums[s] = temp;
            }
            while(s<end&&nums[s] <= nums[start]){//第一个比nums[0]大的数
                s++;
            }
            if(s == nums.size())break;
            while(nums[e] > nums[start]){//第一个小于等于nums[0]的数
                e--;
            }
        }
        if(s == end){
            s -- ;
        }else if(e == start){
            return start;
        }
        /*与最后的nums[s]交换*/
        int temp = nums[e];
        nums[e] = nums[start];
        nums[start] = temp;
        return e;
    }
    int findKthLargest(vector<int>& nums, int k , int start, int end){
        cout << "k = " << k << endl;
        cout << "(" << start << ", " << end << ")" << endl;
        for(int i:nums){
            cout << i << " ";
        }
        cout << endl;
        if(end-start==1){
            return start;
        }else{
            int pos = shift(nums, start, end);
            for(int i:nums){
                cout << i << " ";
            }
            cout << endl;
            cout << "pos = " << pos << endl;
            if(end-pos==k)return pos;
            else if(end-pos>k){//这里需要注意，刚刚挪动的数在这里是最小的，可能不会有任何变化
                return findKthLargest(nums, k, pos+1, end);
            }else{//在左边没事，刚刚调整过的数是最大的，第一个数肯定不是它
                return findKthLargest(nums, k - (end-pos),start, pos);
            }
        }
    }
public:
    /**
     * 找到整个数组第k大的数对应的下标
    */
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size());
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int pos = findKthLargest(arr, arr.size()-k);
        vector<int>result;
        for(int i=0;i<pos;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};

int main(){
    vector<int> array;
    Solution s;
    int temp;
    int k;
    cin >> k;
    while(cin >> temp){
        array.push_back(temp);
    }
    cout << s.findKthLargest(array, k);
    return 0;
}