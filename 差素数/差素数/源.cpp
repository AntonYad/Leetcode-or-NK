#include<iostream>
using namespace std;
bool issushu(int j);
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = n / 2; i>1; i--)
		{
			if (issushu(i) && issushu(n - i))
			{
				cout << i << endl;
				cout << n - i << endl;
				break;
			}
		}
	}
	return 0;
}
bool issushu(int j)
{
	if (j == 1 || j == 2)
	{
		return true;
	}
	for (int i = 2; i<j; i++)
	{
		if (j%i == 0)
		{
			return false;
		}
	}
	return true;
}