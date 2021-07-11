class Solution {
public:
    unordered_map<string, map<string, int>> res;
    vector<string> v;
    bool _findItinerary(int num)
    {
        if (v.size() == num + 1)
        {
            return true;
        }
        for (auto& e : res[v[v.size() - 1]])
        {
            if (e.second > 0)
            {
                v.push_back(e.first);
                e.second--;
                if (_findItinerary(num))
                {
                    return true;
                }
                e.second++;
                v.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& e : tickets)
        {
            res[e[0]][e[1]]++;
        }
        //unordered_map<string,map<string,int>> res;
        v.push_back("JFK");
        _findItinerary(tickets.size());
        return v;

    }
};