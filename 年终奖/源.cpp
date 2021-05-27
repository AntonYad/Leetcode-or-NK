int getMost(vector<vector<int> > board) {
    // write code here
    vector<vector<int>> vv;
    for (int i = 0; i < 6; i++)
    {
        vector<int> tmp(6, 0);
        vv.push_back(tmp);
    }
    vv[0][0] = board[0][0];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if (i == 0 && j != 0)
            {
                vv[i][j] = vv[i][j - 1] + board[i][j];
            }
            else if (j == 0 && i != 0)
            {
                vv[i][j] = vv[i - 1][j] + board[i][j];
            }
            else
            {
                vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]) + board[i][j];
            }
        }
    }
    return vv[5][5];

}
};