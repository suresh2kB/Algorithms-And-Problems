/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

int dfs(int u, vector<int> &vis)
{
    vis[u] = 1;

    int curr = 1;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            curr += dfs(v, vis);
        }
    }

    return curr;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    Adj.clear();
    Adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    vector<int> arr;

    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int curr = dfs(i, vis);
            arr.push_back(curr);
        }
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            ans += (arr[i] * arr[j]);
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
