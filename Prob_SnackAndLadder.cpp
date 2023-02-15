/**
 *    author:  Suresh Kumar
 *    created: 15.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;

vector<int> intToRowCol(int val, int n)
{
    int r = (val - 1) / n;
    int c = 0;
    if (r % 2 == 0)
    {
        c = (val - 1) % n;
    }
    else
    {
        c = n - 1 - (val - 1) % n;
    }
    return {r, c};
}
int snackAndLadder()
{
    int len = grid.size();
    int sz = len * len;
    reverse(grid.begin(), grid.end());
    vector<int> vis(sz, 0);
    queue<pair<int, int>> q;
    q.push({1, 0}); // Current node, Steps
    vis[1] = 1;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int val = it.first;
        int step = it.second;

        for (int num = 1; num <= 6; num++)
        {
            int next = val + num;

            vector<int> rowAndCol = intToRowCol(next, len);
            int r = rowAndCol[0];
            int c = rowAndCol[1];

            if (grid[r][c] != -1)
            {
                next = grid[r][c];
            }
            if (next == len * len)
            {
                return step + 1;
            }

            if (vis[next] == 0)
            {
                vis[next] = 1;
                q.push({next, step + 1});
            }
        }
    }

    return -1;
}
void solve()
{
    int numberOfRows, numberOfColumns;
    cin >> numberOfRows >> numberOfColumns;

    grid.resize(numberOfRows, vector<int>(numberOfColumns, 0));

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << snackAndLadder() << endl;
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
