#include<iostream>
using namespace std;
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		if (month<1 || month>12)
		{
			return -1;
		}
		if (day<1 || day>31)
		{
			return -1;
		}
		int sumday = days[month - 1] + day;
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month>2)
		{
			sumday++;
		}
		cout << sumday << endl;
	}
	return 0;
}