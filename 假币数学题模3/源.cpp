#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            continue;
        }
        int count = 0;
        while (n >= 2)
        {
            count++;
            if (n % 3)
            {
                n = n / 3 + 1;
            }
            else
            {
                n = n / 3;
            }
        }
        cout << count << endl;
    }
    return 0;
}