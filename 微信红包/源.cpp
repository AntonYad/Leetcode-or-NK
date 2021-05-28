class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if (gifts.size() < 0)
        {
            return 0;
        }
        map<int, int> m;
        for (auto& e : gifts)
        {
            m[e]++;
        }
        int l = n / 2;
        for (auto& e : m)
        {
            if (e.second > l)
            {
                return e.first;
            }
        }
        return 0;
    }
};