class Solution {
public:
    void reOrderArray(vector<int>& array) {

        int len = array.size();
        if (len <= 1) return;
        int index = 0;
        vector<int> temp(len, 0);
        for (int i = 0; i < len; ++i) {
            if (array[i] % 2 == 1) temp[index++] = array[i];
        }

        for (int i = 0; i < len; ++i) {
            if (array[i] % 2 == 0) temp[index++] = array[i];
        }

        for (int i = 0; i < array.size(); i++)
        {
            array[i] = temp[i];
        }
    }
};