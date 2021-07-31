class Solution {
public:
    bool isNumeric(char* string)
    {
        bool flag = false;
        bool dian = false;
        bool mi = false;
        for (int i = 0; i < strlen(string); i++)
        {
            if (string[i] == 'e' || string[i] == 'E')
            {
                if (i == strlen(string) - 1)return false;
                if (mi)return false;
                mi = true;
            }
            else if (string[i] == '+' || string[i] == '-')
            {
                if (flag && string[i - 1] != 'e' && string[i - 1] != 'E')
                {
                    return false;
                }
                if (!flag && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E')return false;
                flag = true;
            }
            else if (string[i] == '.')
            {
                if (mi || dian)return false;
                dian = true;
            }
            else if (string[i] < '0' || string[i] > '9') // ²»ºÏ·¨×Ö·û
                return false;
        }
        return true;
    }

};