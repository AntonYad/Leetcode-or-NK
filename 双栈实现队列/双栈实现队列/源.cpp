class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		first.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (last.empty())
		{
			inout();
		}
		int cur = last.top();
		last.pop();
		return cur;
	}

	/** Get the front element. */
	int peek() {
		if (last.empty())
		{
			inout();
		}
		return last.top();

	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return last.empty() && first.empty();
	}
private:
	stack<int> first;
	stack<int> last;
	void inout()
	{
		while (!first.empty())
		{
			last.push(first.top());
			first.pop();
		}
	}