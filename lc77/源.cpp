class Solution {
private:
    vector<vector<int>> result; // ��ŷ�����������ļ���
    vector<int> path; // ������ŷ����������
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // ����ڵ� 
            backtracking(n, k, i + 1); // �ݹ�
            path.pop_back(); // ���ݣ���������Ľڵ�
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // ���Բ�д
        path.clear();   // ���Բ�д
        backtracking(n, k, 1);
        return result;
    }
};
