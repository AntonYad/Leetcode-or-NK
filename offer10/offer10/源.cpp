
class Solution {
public:
	int fib(int n)
	{
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 1;
		vector<int> result(n + 1, 0);

		result[0] = 0;
		result[1] = 1;

		for (int i = 2; i < n + 1; i++)
			result[i] = (result[i - 1] + result[i - 2]) % 1000000007;

		return result[n];
	}
};