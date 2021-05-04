class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty())
		{
			return false;
		}
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				if (matrix[i][j] == target)
				{
					return true;
				}
			}
		}
		return false;
	}
};