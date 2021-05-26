class Solution {
public:
    /**
     *
     * @param S string�ַ���
     * @param T string�ַ���
     * @return int����
     */
    int numDistinct(string S, string T) {
        // write code here
        int row = S.size();
        int col = T.size();
        if (T.empty())
        {
            return 1;
        }
        if (S.empty())
        {
            return 0;
        }
        vector<vector<int>> mart(row + 1, vector<int>(col + 1, 0));
        for (int i = 0; i <= row; i++)
        {
            mart[i][0] = 1;
        }
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (S[i - 1] == T[j - 1])
                {
                    mart[i][j] = mart[i - 1][j] + mart[i - 1][j - 1];
                }
                else
                {
                    mart[i][j] = mart[i - 1][j];
                }
            }
        }
        return mart[row][col];
    }
};