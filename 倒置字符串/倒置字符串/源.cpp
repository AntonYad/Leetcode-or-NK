#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int i = 0,j = 0;
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	while (i < str.size())
	{
		while (i < str.size() && str[i] == ' ')
		{
			i++;
		}
		j = i;
		while (i < str.size() && str[i] != ' ')
		{
			i++;
		}
		reverse(str.begin() + j, str.begin() + i);
	}
	cout << str << endl;
	return 0;
}