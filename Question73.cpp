#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        bool col_zero = false;
        bool row_zero = false;
        /*记录相关的信息*/
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(matrix[i][j] == 0){
                    if(i!=0){
                        matrix[i][0] = 0;
                    }else{
                        row_zero = true;
                    }
                    if(j!=0){
                        matrix[0][j] = 0;
                    }else{
                        col_zero = true;
                    }
                }
            }
        }
        /*开始列置零*/
        for(int i=0;i<width;i++){
            if(matrix[0][i] == 0){
                for(int j=0;j<height;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        /*开始行置零*/
        for(int i=0;i<height;i++){
            if(matrix[i][0] == 0){
                for(int j=0;j<width;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(col_zero){
            for(int i=0;i<height;i++){
                matrix[i][0] = 0;
            }
        }
        if(row_zero){
            for(int i=0;i<width;i++){
                matrix[0][i] = 0;
            }
        }
    }
};