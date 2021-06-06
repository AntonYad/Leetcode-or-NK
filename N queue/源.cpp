class Solution {
public:
    bool Is(vector<pair<int, int>>& solution, int row, int col)
    {
        for (auto e : solution)
        {
            if (col == e.second || (e.first + e.second == row + col) || (e.first - e.second == row - col))
            {
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<pair<int, int>>>& solutions, vector<pair<int, int>>& solution, int row, int n)
    {
        if (row == n)
        {
            solutions.push_back(solution);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (Is(solution, row, i))
            {
                solution.push_back(make_pair(row, i));
                dfs(solutions, solution, row + 1, n);
                solution.pop_back();
            }
        }
    }
    vector<vector<string>> rev(vector<vector<pair<int, int>>>& solutions, int n)
    {
        vector<vector<string>> strstr;
        for (auto e : solutions)
        {
            vector<string> str(n, string(n, '.'));
            for (auto n : e)
            {
                str[n.first][n.second] = 'Q';
            }
            strstr.push_back(str);
        }
        return strstr;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<pair<int, int>>> solutions;
        vector<pair<int, int>> solution;
        dfs(solutions, solution, 0, n);
        return rev(solutions, n);
    }
};