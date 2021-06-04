class Solution {
public:
    void dfs(string tiles, vector<int>& used, set<string>& ret, string str)
    {
        if (!str.empty())
        {
            ret.insert(str);
        }
        for (int i = 0; i < tiles.size(); i++)
        {
            if (used[i] == 0)
            {
                used[i] = 1;
                dfs(tiles, used, ret, str + tiles[i]);
                used[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> ret;
        int len = tiles.size();
        vector<int> used(len + 1, 0);
        string str = "";
        if (tiles.empty())
        {
            return 0;
        }
        dfs(tiles, used, ret, str);
        return ret.size();
    }
};