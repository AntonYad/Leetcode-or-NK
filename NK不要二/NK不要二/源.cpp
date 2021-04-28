#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int W, H;
	cin >> W;
	cin >> H;
	int count = 0;
	//vector<vector<int>> v(H+1,vector<int>(W+1,0));
	int v[1000][1000] = { 0 };
	for (int i = 0; i<W; i++)
	{
		for (int j = 0; j<H; j++)
		{
			if (v[i][j] == 0)
			{
				count++;
				if ((i + 2)<W)
				{
					v[i + 2][j] = -1;
				}
				if ((j + 2)<H)
				{
					v[i][j + 2] = -1;
				}
			}

		}
	}
	cout << count << endl;
	return 0;
}