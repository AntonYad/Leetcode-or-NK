class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        vector<int> v(nums.size(), -1);
        if (nums.size() == 0) return v;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++)
        {
            while (!st.empty() && nums[i] > nums[st.top()])
            {
                v[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        v.resize(v.size() / 2);
        return v;
    }
};