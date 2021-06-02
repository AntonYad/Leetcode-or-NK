int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& book,
		int x, int y)
	{
		//����ǰ�߼�
		book[x][y] = 1;
		//����ÿһ�ֿ��ܣ��ĸ�����
		for (int k = 0; k < 4; ++k)
		{
			int nX = x + nextPosition[k][0];
			int nY = y + nextPosition[k][1];
			//�ж���λ���Ƿ�Խ��
			if (nX >= row || nX < 0
				|| nY >= col || nY < 0)
				continue;
			//�������Ҫ�󣬲���֮ǰҲû����Ⱦ�����������Ⱦ
			if (grid[nX][nY] == '1' && book[nX][nY] == 0)
			{
				dfs(grid, row, col, book, nX, nY);
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty())
			return 0;
		int ret = 0;

		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> book;
		book.resize(row);
		for (int i = 0; i < row; ++i)
			book[i].resize(col, 0);
		//��ÿһ�������Ϊ��Ⱦ��㿪ʼ
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == '1' && book[i][j] == 0)
				{
					++ret;
					dfs(grid, row, col, book, i, j);
				}
			}
		}
		return ret;
	}
};