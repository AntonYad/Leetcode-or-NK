// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int res = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[i] > v[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}