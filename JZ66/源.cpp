class Solution {
public:

    int getvalue(int row, int col) {
        int sum = 0;
        while (row != 0)
        {
            sum += row % 10;
            row = row / 10;
        }

        while (col != 0)
        {
            sum += col % 10;
            col = col / 10;
        }
        return sum;
    }
    void _movingCount(int threshold, int rows, int cols, int i, int j, int& count, vector<vector<int>>& used)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || used[i][j] == 1) return;
        if (getvalue(i, j) > threshold)
        {
            used[i][j] = 1;
            return;
        }
        used[i][j] = 1;
        count++;
        _movingCount(threshold, rows, cols, i + 1, j, count, used);
        _movingCount(threshold, rows, cols, i - 1, j, count, used);
        _movingCount(threshold, rows, cols, i, j + 1, count, used);
        _movingCount(threshold, rows, cols, i, j - 1, count, used);
    }
    int movingCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0) return 0;
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        int count = 0;
        _movingCount(threshold, rows, cols, 0, 0, count, used);
        return count;
    }
};