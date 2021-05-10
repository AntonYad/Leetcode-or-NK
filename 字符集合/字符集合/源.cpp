class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] == x)
			{
				return i;
			}
		}
		return 0;
	}
};