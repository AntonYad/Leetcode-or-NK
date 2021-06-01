#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<int> f(100001, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        f[i] = f[i] % 1000000;
    }
    int n;
    while (cin >> n)
    {
        if (n > 29)
        {
            printf("%06d\n", f[n]);
        }
        else
        {
            printf("%d\n", f[n]);
        }
    }
    return 0;
}