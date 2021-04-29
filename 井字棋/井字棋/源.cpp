
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int len = board.size();
		//检查行
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//检查列
		for (int i = 0; i<len; i++)
		{
			int sum = 0;
			for (int j = 0; j<len; j++)
				sum += board[j][i];
			if (sum == len)
				return true;
		}
		//检查主对角线
		int temp = 0;
		for (int i = 0; i<len; i++)
		{
			temp += board[i][i];
		}
		if (temp == len) return true;

		//检查副对角线
		temp = 0;
		for (int i = 0; i<len; i++)
		{
			temp += board[i][len - i - 1];
		}
		if (temp == len) return true;

		return false;
	}
};