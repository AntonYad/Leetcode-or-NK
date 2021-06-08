class Solution {
public:
    bool Is(vector<pair<int, int>>& solution, int row, int i)
    {
        for (auto e : solution)
        {
            if (e.second == i || e.first + e.second == row + i || e.first - e.second == row - i)
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
    int totalNQueens(int n)
    {
        vector<vector<pair<int, int>>> solutions;
        vector<pair<int, int>> solution;
        dfs(solutions, solution, 0, n);
        return solutions.size();
    }
};