class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); i++)
        {
            int res = gas[i] - cost[i];
            int index = (i + 1) % cost.size();
            while (res > 0 && index != i)
            {
                res += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            if (res >= 0 && index == i)
            {
                return i;
            }
            // res.clear();
        }
        return -1;
    }
};