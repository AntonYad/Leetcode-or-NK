#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string AddLonginteger(string addend, string augend)
{
	string res = " ";
	int carry = 0;
	int addlen = addend.size() - 1;
	int auglen = augend.size() - 1;
	while (addlen >= 0 || auglen >= 0)
	{
		if (addlen >= 0)
		{
			carry = carry + addend[addlen] - '0';
		}
		if (auglen >= 0)
		{
			carry = carry + augend[auglen] - '0';
		}
		res += (char)(carry % 10 + '0');
		carry = carry / 10;
		addlen--;
		auglen--;
	}
	if (carry == 1)
	{
		res += (char)carry;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << AddLonginteger(s1, s2) << endl;
	return 0;
}