#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            continue;
        }
        long a = pow(5, n) - 4;
        long b = pow(4, n) + n - 4;
        cout << a << " " << b << endl;
    }
    return 0;
}