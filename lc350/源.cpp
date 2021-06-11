class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums2.size(); i++)
        {
            um[nums2[i]]++;
        }
        vector<int> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (auto& e : um)
            {
                if (nums1[i] == e.first)
                {
                    if (e.second > 0)
                    {
                        v.push_back(e.first);
                        e.second--;
                    }

                }
            }
        }
        return v;
    }
};