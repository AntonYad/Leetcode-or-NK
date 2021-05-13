//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int v[1000] = { 0 };
//		int i = n;
//		while (i)
//		{
//			int j = 0;
//			v[j] = i % 2;
//			i = i / 2;
//			j++;
//		}
//		int count = 0;
//		for (int i = 0; i<1000; i++)
//		{
//			if (v[i] == 1)
//			{
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			int j = 0;
			if (n % 2 == 1)
			{
				count++;
			}
			n = n / 2;
		}
		cout << count << endl;
	}
	return 0;
}