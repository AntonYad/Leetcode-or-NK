class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1;
        unordered_set<int> us2;
        for (int i = 0; i < nums1.size(); i++)
        {
            us1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            us2.insert(nums2[i]);
        }
        vector<int> v;
        for (auto& e1 : us1)
        {
            for (auto& e2 : us2)
            {
                if (e1 == e2)
                {
                    v.push_back(e2);
                }
            }
        }
        return v;
    }
};