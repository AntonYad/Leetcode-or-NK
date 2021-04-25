class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
		{
			return vector<int>();
		}
		int m = matrix.size(); //��
		int n = matrix.at(0).size(); //��
		int size = m * n;
		vector<int> v;
		v.reserve(size);
		int row = 0;
		int col = 0;
		int direction = 0;
		for (int i = 0; i < size; ++i)
		{
			v.push_back(matrix.at(row).at(col));

			if (direction == 0) //������������
			{
				if (row == 0 && col < n - 1) //���м���ͷ
				{
					++col;
					direction = 1;
				}
				else if (col == n - 1) //�мӵ�ͷ
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
			else if (direction == 1) //������������
			{
				if (row < m - 1 && col == 0) //���м���ͷ
				{
					++row;
					direction = 0;
				}
				else if (row == m - 1) //�мӵ�ͷ
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