#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        cout << n << " = ";
        for (int i = 2; i <= sqrt(n); ++i) {
            //������ͬһ������ֱ�����������ų��պ��Ǹ�����n�η������
            while (n % i == 0 && n != i) {
                cout << i << " * ";
                n /= i;//���������޸�n��ֵ
            }
        }
        cout << n << endl;
    }
    return 0;
}