#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    int squares[100];
    int max_length;
    int length[10001];
    int numSquares(int n) {
        int j=100;
        for(int i=0;i<100;i++){
            squares[i] = j*j;
            j--;
        }
        int cur = 0;//最大的平方数
        return max_length;
    }
};