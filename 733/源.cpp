int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution
{
public:
    void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& used, int sr, int sc, int newColor, int oldColor)
    {
        image[sr][sc] = newColor;
        used[sr][sc] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newsr = sr + nextPosition[i][0];
            int newsc = sc + nextPosition[i][1];
            if (newsr >= row || newsr < 0 || newsc >= col || newsc < 0)
            {
                continue;
            }

            if (image[newsr][newsc] == oldColor && used[newsr][newsc] == 0)
            {
                dfs(image, row, col, used, newsr, newsc, newColor, oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if (image.empty())
        {
            return image;
        }

        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> used(row + 1, vector<int>(col + 1, 0));
        int oldColor = image[sr][sc];
        dfs(image, row, col, used, sr, sc, newColor, oldColor);
        return image;
    }
};