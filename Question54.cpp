#include <vector>
#include <list>
#include <iostream>

using namespace std;
class pos{
public:
    int r,c;
public:
    pos(){}
    pos(int a, int b):r(a), c(b){}
    void setPos(int a, int b){
        r = a;
        c = b;
    }
    void right(){
        c++;
    }
    void left(){
        c--;
    }
    void up(){
        r--;
    }
    void down(){
        r++;
    }
};
class myIter{
private:
    int max_r, min_r, max_c, min_c;
    pos current_position;
    int former_direction;
public:
    myIter(int a, int b, int c, int d):min_r(a), max_r(b), min_c(c), max_c(d), former_direction(-1),current_position(0,0){}
    /**
     * 一口气走到头，把路上的位置输出成列表，按照右、下、左、上的顺序
    */
    list<pos> move(){
        list<pos> result;
        former_direction += 1;
        former_direction %= 4;
        switch (former_direction){
            case 0://一直往右
                for(int i=current_position.c;i+1<max_c;i++){
                    current_position.right();
                    result.push_back(current_position);
                }
                max_c--;
                break;
            case 1://往下
                for(int i=current_position.r;i+1<max_r;i++){
                    current_position.down();
                    result.push_back(current_position);
                }
                max_r--;
                break;
            case 2://往左
                for(int i=current_position.c;i-1>min_c;i--){
                    current_position.left();
                    result.push_back(current_position);
                }
                min_c++;
                break;
            case 3://往上
                for(int i=current_position.c;i-1>min_r;i--){
                    current_position.up();
                    result.push_back(current_position);
                }
                min_c++;
                break;
        }
        return result;
    }
    bool movable(){
        int temp = (former_direction+1)%4;
        switch(temp){
            case 0:
                return (current_position.c+1<max_c)||(current_position.r+1<max_r);
            case 1:
                return (current_position.r+1<max_r)||(current_position.c-1>min_c);
            case 2:
                return (current_position.r+1<max_r)||(current_position.c-1>min_c);
            case 3:
                return (current_position.c+1<max_c)||(current_position.r-1>min_r);

        }
        return false;
    }
};
class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        myIter it(0, height, 0, width);
        vector<int> result;
        result.push_back(matrix[0][0]);
        while(it.movable()){
            list<pos> line = it.move();
            for(pos p:line){
                cout << p.r << " " << p.c << endl;
                result.push_back(matrix[p.r][p.c]);
            }
        }
        return result;
    }
};