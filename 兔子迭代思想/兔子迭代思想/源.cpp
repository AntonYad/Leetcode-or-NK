#include<bits/stdc++.h>
using namespace std;
int getTotalCount(int m)
{
	int t1 = 1, t2 = 0, t3 = 0;
	while (--m)
	{
		t3 = t3 + t2;
		t2 = t1;
		t1 = t3;
	}
	return t1 + t2 + t3;
}
int main()
{
	int month;
	while (cin >> month)
	{
		cout << getTotalCount(month) << endl;
	}
	return 0;
}