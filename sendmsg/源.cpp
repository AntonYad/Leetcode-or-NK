#include<iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        long long f[21] = { 0,0,1 };
        for (int i = 3; i < 21; i++)
        {
            f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
        }
        cout << f[n] << endl;
    }
    return 0;
}