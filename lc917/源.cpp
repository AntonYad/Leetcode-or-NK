class Solution {
public:
    string reverseOnlyLetters(string s) {
        if (s == "")
        {
            return s;
        }
        auto left = 0;
        auto right = s.size() - 1;
        while (left < right)
        {
            while (left < right)
            {
                if (s[left] >= 'a' && s[left] <= 'z' || s[left] >= 'A' && s[left] <= 'Z')
                {
                    break;
                }
                left++;
            }
            while (left < right)
            {
                if (s[right] >= 'a' && s[right] <= 'z' || s[right] >= 'A' && s[right] <= 'Z')
                {
                    break;
                }
                right--;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};