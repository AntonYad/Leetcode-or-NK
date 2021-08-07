class Solution {
private:
    int count = 0;
    priority_queue<int, vector<int>, less<int>> left_big;
    priority_queue<int, vector<int>, greater<int>> right_small;
public:
    void Insert(int num)
    {
        count++;
        if (count % 2 == 1) { //ÆæÊý
            right_small.push(num);
            left_big.push(right_small.top());
            right_small.pop();
        }
        else {

            left_big.push(num);
            right_small.push(left_big.top());
            left_big.pop();
        }
    }

    double GetMedian()
    {

        if (count % 2 == 1) return left_big.top();
        else {
            return double((left_big.top() + right_small.top()) / 2.0);
        }
    }

};
