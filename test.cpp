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
    time_t start_1 = clock();
    for(int (&cur)[1000]:arr1){
        for(int &i:cur){
            i = constFunc();
        }
    }
    time_t end_1 = clock();
    cout << end_1 - start_1 << endl;
    /* 列优先遍历 */
    time_t start_2 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr2[j][i] = constFunc();
        }
    }
    time_t end_2 = clock();
    cout << end_2 - start_2 << endl;
    /* 行优先遍历 */
    time_t start_3 = clock();
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr3[i][j] = constFunc();
        }
    }
    time_t end_3 = clock();
    cout << end_3 - start_3 << endl;
    return 0;
}