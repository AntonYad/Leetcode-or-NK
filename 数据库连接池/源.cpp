#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int count = 0;
        int maxcount = 0;
        string id;
        string me;
        while (n--)
        {
            cin >> id >> me;
            if (me == "connect")
            {
                count++;
            }
            else if (me == "disconnect")
            {
                count--;
            }
            if (count > maxcount)
            {
                maxcount = count;
            }
        }
        cout << maxcount << endl;
    }
    return 0;
}