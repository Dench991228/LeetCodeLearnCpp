#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX 1000

double x[MAX], A[MAX][MAX], Y[MAX];

int main(){
    ifstream data_txt;
    ifstream x_txt;
    data_txt.open("./data.txt");
    x_txt.open("./x.txt");
    /*输入A矩阵*/
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            data_txt >> A[i][j];
            //cout << A[i][j]<< endl;
        }
    }
    cout << "----x----" << endl;
    /*输入B矩阵*/
    for(int i=0;i<MAX;i++){
        x_txt >> x[i];
        //cout << x[i] << endl;
    }
    memset(Y, 0, sizeof(int)*MAX);
    /*开始操作*/
    /*方式一*/
    chrono::time_point<chrono::system_clock> start_1 = chrono::system_clock::now();
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            Y[i] += A[i][j] * x[j];
        }
    }
    chrono::time_point<chrono::system_clock> end_1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_1 = end_1 - start_1;
    cout << "第一种方式消耗时间：" << endl;
    cout << elapsed_1.count() << endl;
    /*方式二*/
    chrono::time_point<chrono::system_clock> start_2 = chrono::system_clock::now();
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            Y[j] += A[j][i] * x[i];
        }
    }
    chrono::time_point<chrono::system_clock> end_2 = chrono::system_clock::now();
    chrono::duration<double> elapsed_2 = end_2 - start_2;
    cout << "第二种方式消耗时间：" << endl;
    cout << elapsed_2.count() << endl;
    return 0;
}