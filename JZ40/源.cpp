class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if (data.size() < 2) return;
        int res = 0;
        for (int i = 0; i < data.size(); i++)
        {
            res = res ^ data[i];
        }
        int pos = 1;
        while ((res & pos) == 0)
        {
            pos = pos << 1;
        }
        num1[0] = 0;
        num2[0] = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] & pos)
            {
                num1[0] ^= data[i];
            }
            else
            {
                num2[0] ^= data[i];
            }
        }
        cout << num1[0] << num2[0] << endl;
    }
};