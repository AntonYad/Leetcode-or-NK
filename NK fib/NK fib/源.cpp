#include<iostream>
using namespace std;
int main()
{
	int n;
	int f0 = 0, f1 = 1, f2;
	int left, right;
	cin >> n;
	while (1)
	{
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
		if (f2<n)
		{
			left = f2;
		}
		if (f2 >= n)
		{
			right = f2;
			break;
		}
	}
	cout << min(n - left, right - n) << endl;
	return 0;

}