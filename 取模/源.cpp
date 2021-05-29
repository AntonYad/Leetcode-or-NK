#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = ((str[i] - 'A' + 21) % 26) + 'A';
            }
        }
        printf("%s\n", str.c_str());
    }
    return 0;
}