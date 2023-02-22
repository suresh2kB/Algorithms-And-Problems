/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool dfs(int u, vector<int> &vis)
{
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            if (dfs(v, vis))
            {
                return true;
            }
        }
        else if (vis[v] == 1)
        {
            return true;
        }
    }

    vis[u] = 2;

    return false;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis))
            {
                cout << "We cannot complete all courses" << endl;
                return;
            }
        }
    }
    cout << "We can complete all the courses" << endl;
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
