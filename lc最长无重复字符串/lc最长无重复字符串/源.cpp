class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
		{
			return 0;
		}
		int count = 0;
		unordered_set<char> set;
		int left = 0; int right = 0;
		while (left<s.size())
		{
			while (right<s.size() && (set.find(s[right]) == set.end()))
			{
				set.insert(s[right]);
				right++;
			}
			count = count>(right - left) ? count : (right - left);

			if (right == s.size())
			{
				break;
			}
			set.erase(s[left]);
			left++;
		}
		return count;
	}
};