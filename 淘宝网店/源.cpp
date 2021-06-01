#include <iostream>
#include <cstdio>
using namespace std;
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int money[13] = { 0,2,1,1,2,1,2,1,2,2,2, 1, 2 };

bool CheckYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	int by, bm, bd;
	int ey, em, ed;
	while (scanf("%d%d%d %d%d%d", &by, &bm, &bd, &ey, &em, &ed) != EOF)
	{
		int ny = by, nm = bm, nd = bd;
		if (CheckYear(ny))
			month[2] = 29;
		else month[2] = 28;
		int count = 0;
		count += money[nm];
		while (1)
		{
			if (ny > ey)
				break;
			else if (ny == ey)
			{
				if (nm > em)
				{
					break;
				}
				else if (nm == em)
				{
					if (nd >= ed)
						break;
				}
			}
			nd += 1;
			count += money[nm];
			if (nd > month[nm])
			{
				nd = 1;
				nm += 1;
				if (nm > 12)
				{
					nm = 1;
					ny += 1;
					if (CheckYear(ny))
						month[2] = 29;
					else month[2] = 28;
				}
			}
		}
		cout << count << endl;
	}
}