class Solution
{
public:
	vector<string> ans;
	vector<string> list = { " ", "!@# ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string>letterCombinations(string digits)
	{
		if (digits.size() == 0)
		{
			return{};
		}
		fun(digits, {}, 0);
		return ans;
	}
	void fun(string digits, string s, int index)
	{
		if (index == digits.size())
		{
			ans.push_back(s);
			return;
		}
		else
		{
			int pos = digits[index] - '0';
			string tmp = list[pos];
			for (int i = 0; i < tmp.size(); i++)
			{
				fun(digits, s + tmp[i], index + 1);
			}
		}
	}
};