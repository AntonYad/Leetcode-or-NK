#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> path_temp;
vector<vector<int>> path_best;

void mazebest(int i, int j)
{
    maze[i][j] = 1;
    path_temp.push_back({ i,j });
    if (i == N - 1 && j == M - 1)
    {
        if (path_best.empty() || path_best.size() > path_temp.size())
        {
            path_best = path_temp;
        }
    }
    if (i - 1 >= 0 && maze[i - 1][j] == 0)//еп╤оио
    {
        mazebest(i - 1, j);
    }
    if (i + 1 < N && maze[i + 1][j] == 0)
    {
        mazebest(i + 1, j);
    }
    if (j - 1 >= 0 && maze[i][j - 1] == 0)
    {
        mazebest(i, j - 1);
    }
    if (j + 1 < M && maze[i][j + 1] == 0)
    {
        mazebest(i, j + 1);
    }
    maze[i][j] = 0;
    path_temp.pop_back();
}
int main()
{
    while (cin >> N >> M)
    {
        maze = vector<vector<int>>(N, vector<int>(M, 0));
        path_temp.clear();
        path_best.clear();
        for (auto& i : maze)
        {
            for (auto& j : i)
            {
                cin >> j;
            }
        }
        mazebest(0, 0);
        for (auto i : path_best)
        {
            cout << '(' << i[0] << ',' << i[1] << ')' << endl;
        }
    }
    return 0;
}