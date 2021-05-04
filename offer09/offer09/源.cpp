class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		q1.push(value);
	}

	int deleteHead() {
		if (q1.empty() && q2.empty())
		{
			return -1;
		}
		else if (q2.empty())
		{
			inout();
		}
		int j = q2.top();
		q2.pop();
		return j;
	}
private:
	stack<int> q1;
	stack<int> q2;
	void inout()
	{
		while (!q1.empty())
		{
			int x = q1.top();
			q2.push(x);
			q1.pop();
		}
	}
};