class Solution {
public:
    void replaceSpace(char* str, int length) {
        int blank = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                blank++;
            }
        }
        int total = 0;
        total = total + length + 2 * blank - 1;
        for (int i = length - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                str[total--] = str[i];
            }
            else
            {
                str[total--] = '0';
                str[total--] = '2';
                str[total--] = '%';
            }
        }
    }
};