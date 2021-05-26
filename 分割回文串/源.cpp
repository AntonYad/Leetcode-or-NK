class Solution {
public:
    /**
     *
     * @param s string×Ö·û´®
     * @return intÕûĞÍ
     */
    bool Isres(string s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                return false;
            }
            ++begin;
            --end;
        }
        return true;
    }
    int minCut(string s)
    {
        // write code here
        int len = s.size();
        vector<int> cur;
        for (int i = 0; i < len; i++)
        {
            cur.push_back(i);
        }
        for (int i = 0; i < len; i++)
        {
            if (Isres(s, 0, i))
            {
                cur[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++)
            {
                if (Isres(s, j + 1, i))
                {
                    cur[i] = min(cur[i], cur[j] + 1);
                }
            }
        }
        return cur[len - 1];
    }
};