
#include<iostream>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            num += s[i] - '0';
        }
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
            if (num == 0 && sum / 10 != 0)
            {
                num = sum;
                sum = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}