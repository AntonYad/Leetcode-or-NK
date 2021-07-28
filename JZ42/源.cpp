class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int>  result;
        if (array.size() == 0)  return result;
        int low = 0, high = array.size() - 1;

        while (low < high) {
            if (array[low] + array[high] == sum) {
                result.push_back(array[low]);
                result.push_back(array[high]);
                return result;
            }
            else if (array[low] + array[high] < sum)  low++;
            else {
                high--;
            }
        }
        return result;
    }
};