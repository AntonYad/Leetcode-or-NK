class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mmap;
        for (auto& e : words)
        {
            mmap[e]++;
        }

        multimap<int, string, greater<int>> mm;
        for (auto& e : mmap)
        {
            mm.insert(make_pair(e.second, e.first));
        }
        vector<string> v;
        auto it = mm.begin();
        while (k--)
        {
            v.push_back(it->second);
            it++;
        }
        return v;
    }
};