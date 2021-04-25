class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
		{
			return vector<int>();
		}
		int m = matrix.size(); //行
		int n = matrix.at(0).size(); //列
		int size = m * n;
		vector<int> v;
		v.reserve(size);
		int row = 0;
		int col = 0;
		int direction = 0;
		for (int i = 0; i < size; ++i)
		{
			v.push_back(matrix.at(row).at(col));

			if (direction == 0) //从左下往右上
			{
				if (row == 0 && col < n - 1) //仅行减到头
				{
					++col;
					direction = 1;
				}
				else if (col == n - 1) //列加到头
				{
					++row;
					direction = 1;
				}
				else
				{
					--row;
					++col;
				}
			}
			else if (direction == 1) //从右上往左下
			{
				if (row < m - 1 && col == 0) //仅列减到头
				{
					++row;
					direction = 0;
				}
				else if (row == m - 1) //行加到头
				{
					++col;
					direction = 0;
				}
				else
				{
					++row;
					--col;
				}
			}
		}
		return v;
	}
};