#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        cout << n << " = ";
        for (int i = 2; i <= sqrt(n); ++i) {
            //反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况
            while (n % i == 0 && n != i) {
                cout << i << " * ";
                n /= i;//能整除就修改n的值
            }
        }
        cout << n << endl;
    }
    return 0;
}