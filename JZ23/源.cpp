class Solution {
public:
    bool Is(vector<int> sequence, int left, int right)
    {
        if (left >= right)
        {
            return true;
        }
        int start = left;
        while (start < right && sequence[start] < sequence[right])
        {
            start++;
        }
        for (int i = start; i < right; i++)
        {
            if (sequence[right] >= sequence[i])
            {
                return false;
            }
        }
        return Is(sequence, 0, start - 1) && Is(sequence, start, right - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
        {
            return false;
        }
        if (sequence.size() == 1)
        {
            return true;
        }
        return Is(sequence, 0, sequence.size() - 1);
    }
};