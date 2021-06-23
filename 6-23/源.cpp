class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        v1.push(val);
        if (v2.empty() || (v2.top() >= v1.top()))
        {
            v2.push(val);
        }
    }

    void pop() {
        if (v1.top() == v2.top())
        {
            v2.pop();
        }
        v1.pop();
    }

    int top() {
        return v1.top();
    }

    int getMin() {
        return v2.top();
    }
private:
    stack<int> v1;
    stack<int> v2;
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = nums[i] ^ res;
        }
        int j = 1;
        while ((res & j) == 0)
        {
            j = j << 1;
        }
        int i1 = 0, i2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & j)
            {
                i1 = i1 ^ nums[i];
            }
            else
            {
                i2 = i2 ^ nums[i];
            }
        }

        return vector<int>{i1, i2};

    }
};