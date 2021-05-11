#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int maxlen = 0;
		while (n)
		{
			if (n & 1)
			{
				++count;
				maxlen = max(count, maxlen);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxlen << endl;
	}
	return 0;
}