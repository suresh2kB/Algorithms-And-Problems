/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<int> X = {-1, 1, 0, 0};
vector<int> Y = {0, 0, -1, 1};

void manhathanDistance(int n, int m)
{
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({i, j});
                // cout << i << " " << j << endl;
            }
        }
    }

    while (!q.empty())
    {
        auto it = q.front();
        int i = it.first;
        int j = it.second;

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = i + X[k];
            int y = j + Y[k];
            if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0 && dist[x][y] == INT_MAX)
            {
                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    grid.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    manhathanDistance(n, m);
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
