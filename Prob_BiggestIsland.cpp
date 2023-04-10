/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
int X[4] = {-1, 1, 0, 0};
int Y[4] = {0, 0, -1, 1};

int dfs(int i, int j)
{
    grid[i][j] = 0;
    int sub_count = 1;

    for (int k = 0; k < 4; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];

        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[x].size() && grid[x][y] == 1)
        {
            sub_count += dfs(x, y);
        }
    }
    return sub_count;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    grid.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, dfs(i, j));
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
