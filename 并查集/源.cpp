#include<iostream>
#include<vector>
class union
{
	union(size_t size)
		:_uft(size,-1)
	{}
	int findroot(int index)
	{
		while (_uft[index]>=0)
		{
			index = _uft[index];
		}
		return index;
	}
	bool union(int x1, int x2)
	{
		int root1 = findroot(x1);
		int root2 = findroot(x2);
		if (root1 == root2)
		{
			return false;
		}
		_uft[root1] += _uft[root2];
		_uft[root2] = root1;
		return true;
	}
	int Count()
	{
		int count = 0;
		for (auto e : _uft)
		{
			if (e < 0)
			{
				count++;
			}
		}
		return count;
	}
private:
	vector<int> _uft;
};