class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (A == 0)
			return B;
		if (B == 0)
			return A;
		int a = A^B, b = (A&B) << 1;
		return addAB(a, b);
	}
};