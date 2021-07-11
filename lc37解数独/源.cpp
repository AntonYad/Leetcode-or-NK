class Solution {
public:
    bool _solveSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++)
                {
                    if (Is(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (_solveSudoku(board))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }

                }
                return false;
            }
        }
        return true;
    }
    bool Is(vector<vector<char>>& board, int row, int col, char k)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == k)
            {
                return false;
            }
        }
        for (int i = 0; i < board[0].size(); i++)
        {
            if (board[i][col] == k)
            {
                return false;
            }
        }
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++)
        {
            for (int j = startcol; j < startcol + 3; j++)
            {
                if (board[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        _solveSudoku(board);
    }
};