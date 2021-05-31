int arr[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& used, int row, int col, int sr, int sc)
    {
        board[sr][sc] = '#';
        used[sr][sc] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newsr = sr + arr[i][0];
            int newsc = sc + arr[i][1];
            if (newsc >= col || newsc < 0 || newsr >= row || newsr < 0)
            {
                continue;
            }
            if (board[newsr][newsc] == 'O' && used[newsr][newsc] == 0 && board[newsr][newsc] != '#')
            {
                dfs(board, used, row, col, newsr, newsc);
            }
        }
    }
    void solve(vector<vector<char>>& board)
    {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> used(row + 1, vector<int>(col + 1, 0));
        if (board.empty())
        {
            return;
        }
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, used, row, col, 0, i);
            }
            if (board[row - 1][i] == 'O')
            {
                dfs(board, used, row, col, row - 1, i);
            }
        }
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, used, row, col, i, 0);
            }
            if (board[i][col - 1] == 'O')
            {
                dfs(board, used, row, col, i, col - 1);
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};