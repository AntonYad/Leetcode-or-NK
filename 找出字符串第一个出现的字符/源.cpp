#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        char v[1000] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            v[(s[i] - 'a')]++;
        }
        int i;
        for (i = 0; i < s.size(); i++)
        {
            if (v[s[i] - 'a'] == 1)
            {
                cout << s[i] << endl;
                break;
            }
        }
        if (i >= s.size())
        {
            cout << -1 << endl;
        }
    }
    return 0;
}