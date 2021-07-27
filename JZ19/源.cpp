class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        if (matrix.empty())
        {
            return v;
        }
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        int left = 0, right = col, up = 0, down = row;
        while (left <= right && up <= down)
        {
            for (int i = left; i <= right; i++)
            {
                v.push_back(matrix[up][i]);
            }
            for (int i = up + 1; i <= down; i++)
            {
                v.push_back(matrix[i][right]);
            }
            if (left < right&& up < down)
            {
                for (int i = right - 1; i > left; i--)
                {
                    v.push_back(matrix[down][i]);
                }
                for (int i = down; i > up; i--)
                {
                    v.push_back(matrix[i][left]);
                }
            }
            up++;
            down--;
            left++;
            right--;
        }
        return v;
    }
};