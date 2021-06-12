#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
int main() {
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        vector<vector<int>> table((n + 1), vector<int>(m + 1));
        vector<vector<double>> P((n + 1), vector<double>(m + 1));
        int x, y;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &x, &y);
            table[x][y] = 1;
        }
        P[1][1] = 1.0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!(i == 1 && j == 1))
                {
                    P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] * (i == n ? 1 : 0.5);
                    if (table[i][j] == 1)
                        P[i][j] = 0;
                }
            }
        }
        printf("%.2lf\n", P[n][m]);
    }
}