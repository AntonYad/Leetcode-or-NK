class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		int i, t;
		for (i = 0; i<intervals.size();)
		{
			int j = i + 1;
			t = intervals[i][1];
			while (j<intervals.size() && t >= intervals[j][0])
			{
				t = max(t, intervals[j][1]);
				j++;
			}
			res.push_back({ intervals[i][0], t });
			i = j;
		}

		return res;
	}
};