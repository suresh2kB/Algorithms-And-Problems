/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<int> X = {-1, 1, 0, 0};
vector<int> Y = {0, 0, 1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    int count = 0;
    while (!q.empty())
    {
        count++;
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int new_x = x + X[k];
                int new_y = y + Y[k];

                if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 0)
                {
                    grid[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
    }

    cout << count - 1 << endl;
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
