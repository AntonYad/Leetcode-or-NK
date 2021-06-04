class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int slow = 0;
        int fast = 1;
        int len = nums.size();
        while (fast < len)
        {
            if (nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};