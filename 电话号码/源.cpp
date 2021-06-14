#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	string s;
	int length;
	string NUM = "22233344455566677778889999";
	while (cin >> length)
	{
		set<string> data;
		int cnt;
		for (int i = 0; i < length; i++)
		{
			cnt = 0;
			string res;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] >= 'A' && s[j] <= 'Z')
				{
					res += NUM[s[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (s[j] >= '0' && s[j] <= '9')
				{
					res += s[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}
		for (set<string>::iterator it = data.begin(); it != data.end(); it++)
			cout << *it << endl;
		cout << endl;
	}
	return 0;
}