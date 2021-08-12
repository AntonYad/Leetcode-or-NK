static int arr[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool bfs(vector<vector<char>>& board, string word, int i, int j, vector<vector<int>>& used,int index)
{
	used[i][j] == 1;
	if (index == word.size())
	{
		return true;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = i + arr[i][0];
		int ny = j + arr[i][1];
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || used[nx][ny] == 1 || board[nx][ny] != word[index])
		{
			continue;
		}
		//==
		if (bfs(board, word, nx, ny, used, index + 1))
		{
			return true;
		}
		used[i][j] == 0;
	}
	return false;
}
bool exits(vector<vector<char>>& board, string word)
{
	vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == word[0])
			{
				if (bfs(board, word, i, j, used,1))
				{
					return true;
				}
			}
		}
	}
	return false;
}