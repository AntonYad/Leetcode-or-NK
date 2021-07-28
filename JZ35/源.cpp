class Solution {
public:
    int InversePairs(vector<int> data)
    {
        if (data.size() == 0)
            return 0;
        vector<int> copy(data);    // 辅助数组，每次递归后有序
        return InversePairsCore(data, copy, 0, data.size() - 1);
    }
    int InversePairsCore(vector<int>& data, vector<int>& copy, int begin, int end)
    {
        if (begin == end)
            return 0;
        int mid = begin + (end - begin) / 2;
        int left = InversePairsCore(copy, data, begin, mid);//这里的一步很绝啊，减少了交换的这一步
        int right = InversePairsCore(copy, data, mid + 1, end);
        int end1 = mid;     // 比较从尾端开始
        int end2 = end;    // 比较从尾端开始
        int index_copy = end;       // 比较结果存入辅助数组尾端
        long res = 0;
        // 归并排序：相当于两个有序数组合成一个有序表（从尾端开始是为了计数）
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