class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		//��pair���λ��
		queue<pair<int, int>> q;
		int row = grid.size();
		int col = grid[0].size();
		//�Ѿ����õ�λ�����
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}
		//�������ӵķ���
		static int nextP[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int step = 0;
		while (!q.empty())
		{
			int n = q.size();
			int flag = 0;
			//�õ�ǰ��һ���Ѿ����õ����Ӵ�����һ��Ҫ���õ�����
			//��Ҫ���������е�����λ��
			while (n--)
			{
				auto Curpos = q.front();
				q.pop();
				//��ǰλ�����ĸ���������
				for (int i = 0; i < 4; ++i)
				{
					int nx = Curpos.first + nextP[i][0];
					int ny = Curpos.second + nextP[i][1];
					//���λ��Խ������ǿո񣬻����Ѿ��Ǹ��õ�λ�ã�������
					if (nx >= row || nx < 0
						|| ny >= col || ny < 0
						|| grid[nx][ny] != 1)
						continue;
					//������µı�����
					flag = 1;
					grid[nx][ny] = 2;
					q.push(make_pair(nx, ny));


				}
			}
			//������µĸ��ã���++
			if (flag)
				++step;
		}
		//�ж��Ƿ����޷����õ�
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return step;
	}
};