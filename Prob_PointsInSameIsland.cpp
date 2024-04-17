/**
 *    author:  Suresh Kumar
 **/

Question: Check if two points are in same island or not.
    
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid, vis;
int X[4] = {-1, 1, 0, 0};
int Y[4] = {0, 0, -1, 1};

void dfs(int i, int j, int color)
{
    grid[i][j] = color;
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];

        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[x].size() && vis[x][y] == 0 && grid[x][y] == 1)
        {
            dfs(x, y, color);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    vis.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (grid[x1][y1] != grid[x2][y2])
        {
            cout << "Not in same island" << endl;
        }
        else
        {
            cout << "Both are in same island" << endl;
        }
    }
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
