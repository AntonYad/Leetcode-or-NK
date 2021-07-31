class Solution
{
public:
    //Insert one char from stringstream
    vector<int> v;
    unordered_map<char, int> um;
    void Insert(char ch) {
        v.push_back(ch);
        um[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (int i = 0; i < v.size(); i++)
        {
            auto it = um.find(v[i]);
            if (it->second == 1)
            {
                return it->first;
            }
        }
        return '#';
    }

};