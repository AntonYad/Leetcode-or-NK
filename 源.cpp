class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>> res(n, vector<int>(n, 0));
		int len = n - 1;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				res[j][len] = matrix[i][j];
			}
			len -= 1;
		}
		matrix = res;
	}
};