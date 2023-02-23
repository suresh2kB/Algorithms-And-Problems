/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<int> X = {-1, 1, 0, 0};
vector<int> Y = {0, 0, -1, 1};

bool cyclePresent(int i, int j, int pi, int pj, vector<vector<char>> grid, vector<vector<int>> &vis, char last)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != last)
    {
        return false;
    }

    if (vis[i][j])
    {
        return true;
    }

    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int new_i = i + X[k];
        int new_j = j + Y[k];

        if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[i].size() && (new_i != pi || new_j != pj))
        {
            if (cyclePresent(new_i, new_j, i, j, grid, vis, grid[i][j]))
            {
                return true;
            }
        }
    }

    return false;
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

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                if (cyclePresent(i, j, -1, -1, grid, vis, grid[i][j]))
                {
                    cout << "Cycle is present in this grid" << endl;
                    return;
                }
            }
        }
    }

    cout << "There is no cycle present in this grid" << endl;
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
