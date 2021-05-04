class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		row = board.size();
		line = board[0].size();
		for (int x = 0; x<row; x++)
		{
			for (int y = 0; y<line; y++)
			{
				if (dfs(board, word, x, y, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
private:
	int row;
	int line;
	bool dfs(vector<vector<char>>& board, string word, int x, int y, int k)
	{
		if (x >= row || x < 0 || y >= line || y < 0 || board[x][y] != word[k])return false;
		if (k == word.size() - 1)return true;
		board[x][y] = '\0';
		bool res = dfs(board, word, x + 1, y, k + 1) || dfs(board, word, x - 1, y, k + 1) || dfs(board, word, x, y + 1, k + 1) || dfs(board, word, x, y - 1, k + 1);
		board[x][y] = word[k];
		return res;
	}
};