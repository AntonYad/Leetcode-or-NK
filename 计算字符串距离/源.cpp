#include<bits/stdc++.h>
using namespace std;
int strdistance(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>> f(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++)
    {
        f[i][0] = i;
    }
    for (int i = 0; i <= len2; i++)
    {
        f[0][i] = i;
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i - 1][j - 1], f[i][j]);
            }
            else
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i - 1][j - 1] + 1, f[i][j]);
            }
        }
    }
    return f[len1][len2];
}
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << strdistance(str1, str2) << endl;
    }
    return 0;
}