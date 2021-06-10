class Solution
{
public:
    int repeatedNTimes(vector<int>& A)
    {
        size_t N = A.size() / 2;
        // ��unordered_mapͳ��ÿ��Ԫ�س��ֵĴ���
        unordered_map<int, int> m;
        for (auto e : A)
            m[e]++;

        // �ҳ����ִ���ΪN��Ԫ��
        for (auto& e : m)
        {
            if (e.second == N)
                return e.first;
        }
        return -1;
    }
};