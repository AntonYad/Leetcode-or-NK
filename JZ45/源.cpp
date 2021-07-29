class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int zerocount = 0;
        int size = 0;
        if (numbers.size() < 5) return false;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] == 0)
            {
                zerocount++;
            }
            else if (numbers[i + 1] == numbers[i])
            {
                return false;
            }
            else
            {
                size += numbers[i + 1] - numbers[i] - 1;
            }
        }
        return zerocount >= size ? true : false;
    }
};