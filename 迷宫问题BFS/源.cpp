static int arr[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct point
{
    int x;
    int y;
    int step;
};
int bfs(vector<string>& v)
{
    queue<point> q;
    point start{ 0,1,0 }, out{ 9,8,0 };
    q.push(start);
    vector<vector<int>> vv(10, vector<int>(10, 0));
    while (!q.empty())
    {
        point cur = q.front();
        vv[cur.x][cur.y] = 1;
        q.pop();
        if (cur.x == out.x && cur.y == out.y)
        {
            return cur.step;
        }
        point next;
        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + arr[i][0];
            next.y = cur.y + arr[i][1];
            if (next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10 && v[next.x][next.y] == '.' && vv[next.x][next.y] == 0)
            {
                next.step = cur.step + 1;
                q.push(next);
            }
        }
    }
    return 0;
}
int main()
{
    vector<string> v(10);
    int i = 0;
    while (cin >> v[i++])
    {
        if (i == 10)
        {
            cout << bfs(v) << endl;
            i = 0;
        }
    }
    return 0;

}