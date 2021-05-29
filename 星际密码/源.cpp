#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = { 1,1 };
    for (int i = 2; i <= 10000; i++)
    {
        v.push_back((v[i - 1] + v[i - 2]) % 10000);
    }
    int n, x;
    while (cin >> n)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            printf("%04d", v[x]);
        }
        cout << endl;
    }
    return 0;
}