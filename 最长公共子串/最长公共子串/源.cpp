#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		string maxstr;
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		for (int i = 0; i < str1.size(); i++)
		{
			for (int j = i; j < str1.size(); j++)
			{
				string tmp = str1.substr(i, j - i + 1);
				if (int(str2.find(tmp)) < 0)
				{
					break;
				}
				else if (maxstr.size() < tmp.size())
				{
					maxstr = tmp;
				}
			}
		}
		cout << maxstr << endl;
	}
	return 0;
}