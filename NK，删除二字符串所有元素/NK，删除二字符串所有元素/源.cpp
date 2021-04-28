#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.size() == 0)
	{
		cout << s1 << endl;
	}
	if (s2.size() == 0)
	{
		cout << s1 << endl;
	}
	auto it1 = s1.begin();
	auto it2 = s2.begin();
	int i = 0;
	while (it1 != s1.end())
	{
		it2 = s2.begin();
		while (it2 != s2.end())
		{
			if (*it1 == *it2)
			{
				it1 = s1.erase(it1);
				it1--;
			}
			else
			{
				it2++;
			}

		}
		it1++;
	}
	cout << s1 << endl;
	return 0;
}