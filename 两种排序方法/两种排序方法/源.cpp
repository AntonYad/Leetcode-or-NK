#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool Islength(vector<string>& v)
{
	for (int i = 0; i + 1<v.size(); i++)
	{
		if (v[i + 1].size()<v[i].size())
		{
			return false;
		}
	}
	return true;
}
bool  lexicographically(vector<string>& v){

	int i = 0;

	while ((i + 1) < v.size()){
		if (v[i].compare(v[i + 1]) >0)
			return 0;
		i++;
	}
	return 1;
}
int main()
{
	int n;
	cin >> n;
	string str;
	vector<string> v;
	for (int i = 0; i<n; i++)
	{
		cin >> str;
		v.push_back(str);
	}
	bool ret = lexicographically(v);
	bool ret1 = Islength(v);
	if (ret1&&ret)
	{
		cout << "both" << endl;
	}
	if (ret1&&!ret)
	{
		cout << "lengths" << endl;
	}
	if (ret&&!ret1)
	{
		cout << "lexicographically" << endl;
	}
	if (!ret&&!ret1)
	{
		cout << "none" << endl;
	}
	return 0;
}