class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int startx = 0, starty = 0;
		int offset = 1;
		int mid = n / 2;
		int count = 1;
		int loop = n / 2;
		int i = 0, j = 0;
		while (loop--)
		{
			i = starty;
			j = startx;
			//1 ×óµ½ÓÒ
			for (; i<starty + n - offset; i++)
			{
				res[startx][i] = count++;
			}
			for (; j<startx + n - offset; j++)
			{
				res[j][i] = count++;
			}
			for (; i>starty; i--)
			{
				res[j][i] = count++;
			}
			for (; j>startx; j--)
			{
				res[j][i] = count++;
			}
			startx++;
			starty++;
			offset += 2;
		}
		if (n % 2 != 0)
		{
			res[mid][mid] = count;
		}
		return res;

	}
};