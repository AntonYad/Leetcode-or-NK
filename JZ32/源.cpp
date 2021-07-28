class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> v;
        for (auto& e : numbers)
        {
            v.push_back(to_string(e));
        }
        sort(v.begin(), v.end(), [](string& a, string& b) {return a + b < b + a; });
        string str;
        for (auto& e : v)
        {
            str += e;
        }
        return str;
    }
};