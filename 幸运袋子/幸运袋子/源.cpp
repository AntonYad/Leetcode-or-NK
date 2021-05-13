#include<iostream>
#include<algorithm>
using namespace std;
int luckybag(int* v, int n, int pos, int sum, int mu)
{
	int count = 0;
	for (int i = pos; i<n; i++)
	{
		sum += v[i];
		mu *= v[i];
		if (sum>mu)
		{
			count += 1 + luckybag(v, n, i + 1, sum, mu);
		}
		else if (v[i] == 1)
		{
			count += luckybag(v, n, i + 1, sum, mu);
		}
		else
		{
			break;
		}
		sum -= v[i];
		mu /= v[i];
		while (i<n - 1 && v[i] == v[i + 1])
		{
			i++;
		}
	}
	return count;
}
int main()
{
	int n;
	int sum, mu;
	int x;
	while (cin >> n)
	{
		int v[n];
		for (int i = 0; i<n; i++)
		{
			cin >> x;
			v[i] = x;
		}
		sort(v, v + n);
		cout << luckybag(v, n, 0, 0, 1) << endl;
	}
	return 0;
}