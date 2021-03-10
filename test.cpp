#include <chrono>
#include <time.h>
#include <iostream>

using namespace std;

int arr1[1000][1000], arr2[1000][1000], arr3[1000][1000];

int func(void){
    return 0x12345;
}

constexpr int constFunc(){
    return 0x12345;
}

int main(){
    /*range 遍历*/
    cout << "实验一" << endl;
    /*先访问一遍，确保三组实验开始前的高速缓存内容一样*/
    for(int (&cur)[1000]:arr1){
        for(int &i:cur){
            i = 1;
        }
    }

    time_t start_1_1 = clock();
    for(int (&cur)[1000]:arr1){
        for(int &i:cur){
            i = 100;
        }
    }
    time_t end_1_1 = clock();
    cout << "range 遍历，用普通函数给数组赋值，消耗时间："<<end_1_1 - start_1_1 << endl;

    time_t start_1_2 = clock();
    for(int (&cur)[1000]:arr1){
        for(int &i:cur){
            i = func();
        }
    }
    time_t end_1_2 = clock();
    cout << "range 遍历，用返回常数的函数给数组赋值，消耗时间："<<end_1_2 - start_1_2 << endl;

    time_t start_1_3 = clock();
    for(int (&cur)[1000]:arr1){
        for(int &i:cur){
            i = constFunc();
        }
    }
    time_t end_1_3 = clock();
    cout << "range 遍历，用constexpr给数组赋值，消耗时间："<<end_1_3 - start_1_3 << endl;
    cout << "实验二" << endl;

    /* 列优先遍历 */

    //先访问一遍arr2，保证每一组实验开始前缓存内容近似一样
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr2[j][i] = 1;
        }
    }

    time_t start_2_1 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr2[j][i] = 100;
        }
    }
    time_t end_2_1 = clock();
    cout << "下标遍历，列优先，用整数字面量给数组赋值，消耗时间：" << end_2_1 - start_2_1 << endl;

    time_t start_2_2 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr2[j][i] = func();
        }
    }
    time_t end_2_2 = clock();
    cout << "下标遍历，列优先，用普通函数给数组赋值，消耗时间：" << end_2_2 - start_2_2 << endl;

    time_t start_2_3 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr2[j][i] = constFunc();
        }
    }
    time_t end_2_3 = clock();
    cout << "下标遍历，列优先，用constexpr给数组赋值，消耗时间：" << end_2_3 - start_2_3 << endl;
    cout << "实验三" << endl;
    /* 行优先遍历 */
    //先访问一遍arr3，保证每一组实验开始前缓存内容近似一样
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr3[i][j] = constFunc();
        }
    }

    time_t start_3_1 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr3[i][j] = 100;
        }
    }
    time_t end_3_1 = clock();
    cout << "下标遍历，行优先，用整数字面量给数组赋值，消耗时间：" << end_3_1 - start_3_1 << endl;

    time_t start_3_2 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr3[i][j] = func();
        }
    }
    time_t end_3_2 = clock();
    cout << "下标遍历，行优先，普通函数给数组赋值，消耗时间：" << end_3_2 - start_3_2 << endl;

    time_t start_3_3 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr3[i][j] = constFunc();
        }
    }
    time_t end_3_3 = clock();
    cout << "下标遍历，行优先，用constexpr给数组赋值，消耗时间：" << end_3_3 - start_3_3 << endl;
    return 0;
}