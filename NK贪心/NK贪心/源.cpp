
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a_i;
	long long max_a_i = 0;
	vector<int> v;
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> a_i;
		v.push_back(a_i);
	}
	sort(v.begin(), v.end());
	int count = n;
	int i = v.size()-1;
	while (count>0 && i > 0)
	{
		v.pop_back();
		max_a_i += v.back();
		v.pop_back();
		count--;
		i--;
	}
	cout << max_a_i << endl;
	return 0;
}