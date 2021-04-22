class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> res(n, vector<int>(m, 4548));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (matrix[i][j] == 0)
				{
					res[i][j] = 0;
				}
			}
		}
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (matrix[i][j] == res[i][j])
				{
					int line = 0, row = 0;
					for (row = 0; row<n; row++)
					{
						matrix[row][j] = 0;
					}
					for (line = 0; line<m; line++)
					{
						matrix[i][line] = 0;
					}
				}
			}
		}
	}
};