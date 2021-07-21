class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
        int max = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int right = i + 1;
            int len = 1;
            while (right < n && A[right] >= A[i])
            {
                right++;
                len++;
            }
            int left = i - 1;
            while (left >= 0 && A[left] >= A[i])
            {
                left--;
                len++;
            }
            if (max < A[i] * len)
            {
                max = A[i] * len;
            }
        }
        return max;
    }
};