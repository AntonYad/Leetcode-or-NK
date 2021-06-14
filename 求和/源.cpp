#include<iostream>
#include<map>
#include<vector>
using namespace std;
void dfs(int index, int sum, vector<int>& v, int& m, int& n)
{
    if (sum > m)
    {
        return;
    }
    if (sum == m)
    {
        for (int j = 0; j < v.size(); j++)
        {
            j < v.size() - 1 ? cout << v[j] << " " : cout << v[j] << endl;
        }
    }
    for (int i = index; i <= n; i++)
    {
        v.push_back(i);
        dfs(i + 1, sum + i, v, m, n);
        v.pop_back();
    }
}
int main()
{
    static int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        dfs(1, 0, v, m, n);
    }
    return 0;
}