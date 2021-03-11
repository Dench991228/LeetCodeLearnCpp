#include <iostream>

using namespace std;

/**
 * 辗转相除法，求出两个整数的最大公因子
 * @param a 第一个参数
 * @param b 第二个参数
 * @return 二者的最大公因数
*/
int euclidian(int a, int b){
    int r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    int a,b;
    while(cin >> a >> b){
        cout << a%b << endl;
    }
    return 0;
}