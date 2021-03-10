#include <vector>
#include <iostream>

using namespace std;

class rectangle{
private:
    int c_1, r_1;
    int c_2, r_2;
    int value;
public:
    rectangle(int row1, int col1, int row2, int col2, int val){
        r_1 = row1;
        c_1 = col1;
        r_2 = row2;
        c_2 = col2;
        value = val;
    }
    bool contain(int r, int c){
        return (r>=r_1&&r<=r_2)&&(c>=c_1&&c<=c_2);
    }
    int getValue(){
        return value;
    }
    void print(){
        cout << r_1 << "," << c_1 << "," << r_2 << "," << c_2 << "," << value << endl;
    }
};

class SubrectangleQueries {
private:
    vector<rectangle> rects = vector<rectangle>();
    vector<vector<int> > matrix;
public:
    SubrectangleQueries(vector<vector<int> >& rectangle) {
        matrix = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        rects.push_back(rectangle(row1, col1, row2, col2, newValue));
    }
    
    int getValue(int row, int col) {
        bool updated = false;
        int updated_value;
        for(rectangle r: rects){
            if(r.contain(row, col)){
                updated_value = r.getValue();
                updated = true;
            }
        }
        return updated?updated_value: matrix[row][col];
    }
};