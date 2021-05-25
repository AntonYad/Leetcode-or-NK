#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        map<string, int> m;
        int i = 0;
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
            {
                if (temp != "")
                {
                    m[temp]++;
                }
                temp = "";
            }
            else
                temp += tolower(s[i]);
        }
        multimap<int, string, greater<int>> mm;
        for (auto& e : m)
        {
            mm.insert(make_pair(e.second, e.first));
        }
        for (auto e : m)
        {
            cout << e.first << ":" << e.second << endl;
        }

    }
    return 0;
}