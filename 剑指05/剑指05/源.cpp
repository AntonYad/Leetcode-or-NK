class Solution {
public:
	string replaceSpace(string s) {
		string s1;
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == ' ')
			{
				s1.push_back('%');
				s1.push_back('2');
				s1.push_back('0');
			}
			else
			{
				s1.push_back(s[i]);
			}
			i++;
		}
		return s1;
	}
};