static int arr[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs(vector<string>& v, vector<vector<int>>& used, int row, int col, int& count)
{
    count++;
    used[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = row + arr[i][0];
        int nc = col + arr[i][1];
        if (nr == 9 && nc == 8)
        {
            count++;
            break;
        }
        if (nr < 0 || nr>9 || nc < 0 || nc >= 9)
        {
            continue;
        }
        if (v[nr][nc] == '.' && used[nr][nc] == 0)
        {
            dfs(v, used, nr, nc, count);
        }
    }
}
int main()
{
    while (1)
    {
        vector<string> v(10);
        for (int i = 0; i < 10; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> used(10, vector<int>(10, 0));
        int count = -1;
        dfs(v, used, 0, 1, count);
        cout << count << endl;
    }
    return 0;
}