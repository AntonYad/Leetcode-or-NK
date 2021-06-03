class Solution {
public:
    void dfs(vector<vector<int>>& solutions, vector<int>& solution, vector<int>& candidates, int previndex, int sum, int target)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                solutions.push_back(solution);
            }
            return;
        }
        for (int i = previndex; i < candidates.size(); i++)
        {
            solution.push_back(candidates[i]);
            dfs(solutions, solution, candidates, i, sum + candidates[i], target);
            solution.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> solutions;
        vector<int> solution;
        int sum = 0;
        dfs(solutions, solution, candidates, 0, sum, target);
        return solutions;
    }
};