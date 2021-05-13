class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		// write code here
		int m = 0, lm = INT_MAX, rm = INT_MAX, leftsum = 0, rightsum = 0;
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				m += left[i];
				m += right[i];
			}
			else
			{
				leftsum += left[i];
				rightsum += right[i];
				if (lm>left[i])
				{
					lm = left[i];
				}
				if (rm>right[i])
				{
					rm = right[i];
				}
			}
		}
		return m + min(leftsum - lm + 1, rightsum - rm + 1) + 1;
	}
};