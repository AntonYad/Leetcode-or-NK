#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	string maxstr;
	int maxlen = 0;
	getline(cin, str);
	int i = 0;
	while (str[i] != '\0')
	{
		while (str[i]<'0' || str[i]>'9')
		{
			i++;
		}
		string tmp;
		int len = 0;
		while (str[i] >= '0'&&str[i] <= '9')
		{
			tmp += str[i];
			i++;
			len++;
			if (len>maxlen)
			{
				maxlen = len;
				maxstr = tmp;
			}
		}
	}
	cout << maxstr << endl;
	return 0;
}