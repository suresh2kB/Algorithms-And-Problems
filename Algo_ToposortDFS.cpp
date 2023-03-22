/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

void dfs(int u, vector<int> &vis, vector<int> &ans)
{
    // cout << u << " ";
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, vis, ans);
        }
    }
    ans.push_back(u);
}
void solve()
{
    // For this one we already consider that graph does not contiain a cycle.
    int V, E;
    cin >> V >> E;
    adj.resize(V);
    vector<int> vis(V, 0);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, ans);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "Topological sort of this graph : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
