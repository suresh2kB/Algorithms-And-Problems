/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<char>> &grid)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
    {
        return 0;
    }

    grid[i][j] = '0';
    return 1 +
           dfs(i + 1, j, grid) + dfs(i - 1, j, grid) +
           dfs(i, j - 1, grid) + dfs(i, j + 1, grid);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                ans = max(ans, dfs(i, j, grid));
            }
        }
    }
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
