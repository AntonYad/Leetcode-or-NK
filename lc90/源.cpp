class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // ������Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > startIndex && nums[i] == nums[i - 1]) { // ע������ʹ��i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ȥ����Ҫ����
        backtracking(nums, 0);
        return result;
    }
};