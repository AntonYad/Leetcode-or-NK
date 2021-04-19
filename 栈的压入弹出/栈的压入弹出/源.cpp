class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int i = 0;
		int j = 0;
		while (i<pushV.size())
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				j++;
			}
			i++;
		}
		if (j == popV.size())
		{
			return true;
		}
		else
			return false;

	}
};