class Solution {
public:
    int InversePairs(vector<int> data)
    {
        if (data.size() == 0)
            return 0;
        vector<int> copy(data);    // �������飬ÿ�εݹ������
        return InversePairsCore(data, copy, 0, data.size() - 1);
    }
    int InversePairsCore(vector<int>& data, vector<int>& copy, int begin, int end)
    {
        if (begin == end)
            return 0;
        int mid = begin + (end - begin) / 2;
        int left = InversePairsCore(copy, data, begin, mid);//�����һ���ܾ����������˽�������һ��
        int right = InversePairsCore(copy, data, mid + 1, end);
        int end1 = mid;     // �Ƚϴ�β�˿�ʼ
        int end2 = end;    // �Ƚϴ�β�˿�ʼ
        int index_copy = end;       // �ȽϽ�����븨������β��
        long res = 0;
        // �鲢�����൱��������������ϳ�һ���������β�˿�ʼ��Ϊ�˼�����
        while (begin <= end1 && mid + 1 <= end2) {
            if (data[end1] > data[end2]) {
                copy[index_copy--] = data[end1--];
                res += end2 - mid;
                res %= 1000000007;
            }
            else
                copy[index_copy--] = data[end2--];
        }
        while (begin <= end1)
            copy[index_copy--] = data[end1--];
        while (mid + 1 <= end2)
            copy[index_copy--] = data[end2--];
        return (left + right + res) % 1000000007;
    }
};