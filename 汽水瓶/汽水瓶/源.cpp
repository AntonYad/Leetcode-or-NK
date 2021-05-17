#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	while (cin >> n)
	{
		//if(n<2)
		//{
		//   cout<<"0"<<endl;
		//}
		if (n == 0)
		{
			return 0;
		}
		int sum = 0;
		int empty = n;
		int count = 0;
		while (empty > 2)
		{
			sum = empty / 3;
			empty = sum + (empty - sum * 3);
			count += sum;
		}
		if (empty == 2)
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}