#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

bool  Is_in(vector<vector<int>> v,int m)
{
	vector<vector<int>> vv;
	sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0]; });
	vector<int> res;
	res.push_back(v[0][0]);
	res.push_back(v[0][1]);
	for (int i = 1; i < v.size(); i++)
	{
		if (res[1] >= v[1][0])
		{
			res[1] = res[1] > v[i][1] ? res[1] : v[i][1];
		}
		else
		{
			vv.push_back(res);
			res[0] = v[i][0];
			res[1] = v[i][1];
		}
	}
	//查询
	for (int i = 1; i < 2; i++)
	{
		if (m > vv[vv.size() - 1][1])//大于最大的
		{
			return false;
		}
		if (m < vv[0][0])//小于最小的
		{
			return false;
		}
		else
		{
			//bool flag = false;
			//for (int j = 0; j < vv.size(); j++)
			//{
			//	if (m[i] >= vv[j][0] && m[i] <= vv[j][1])
			//	{
			//		flag = true;
			//		break;
			//	}
			//}
			int left = 0;
			int right = vv.size()-1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (m > vv[mid][1])
				{
					left = mid + 1;
				}
				else if (m < vv[mid][0])
				{
					right = mid - 1;
				}
				else 
				{
						return true;
				}
			}
			return false;
		}
	}
	return true;
}
int main()
{
	vector<vector<int>> vv = {{6,9},{1,5}};
	auto res = Is_in(vv, 4);
		cout << res << endl;
	return 0;
}