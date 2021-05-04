class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> s;
		for (int i = 0; i<n; i++)
		{
			if (A[i] == '(')
			{
				s.push(A[i]);
			}
			else if (A[i] == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					return false;
				}
				else
				{
					s.pop();
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};