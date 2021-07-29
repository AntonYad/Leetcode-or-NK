class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if (A.size() <= 1)
        {
            return res;
        }
        for (int i = 0; i < A.size(); i++)
        {
            int temp = 1;
            for (int j = 0; j < A.size(); j++)
            {
                if (i != j)
                    temp *= A[j];

            }
            res.push_back(temp);
        }
        return res;
    }
};