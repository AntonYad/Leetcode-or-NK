class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> v(nums1.size(), -1);
        if (nums1.size() == 0) return v;
        stack<int> st;
        unordered_map<int, int> us;
        for (int i = 0; i < nums1.size(); i++) {
            us[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); i++)
        {
            while (!st.empty() && nums2[i] > nums2[st.top()])
            {
                if (us.find(nums2[st.top()]) != us.end())
                {
                    int index = us[nums2[st.top()]];
                    v[index] = nums2[i];
                    st.pop();
                }
                else
                {
                    st.pop();
                }
            }
            st.push(i);
        }
        return v;
    }
};