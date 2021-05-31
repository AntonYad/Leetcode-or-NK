#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int year;
    while (cin >> year)
    {
        vector<string> v1 = { "-01-01","-01-21","-02-18","-05-27","-07-04","-09-02","-11-28","-12-25" };
        //»ÚƒÍ
        vector<string> v2 = { "-01-01","-01-20","-02-17","-05-26","-07-04","-09-01","-11-27","-12-25" };
        if (year %2==0)
        {
            for (auto& e : v2)
            {
                cout << year << e << endl;
            }
        }
        else
        {
            for (auto& e : v1)
            {
                cout << year << e << endl;
            }
        }
    }
    return 0;
}