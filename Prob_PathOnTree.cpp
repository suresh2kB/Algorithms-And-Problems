/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<pair<int, int>> adj[N];
int dist[N];

void dfs(int u, int p)
{
    for (auto it : adj[u])
    {
        int v = it.first;
        int w = it.second;
        if (v != p)
        {
            dist[v] = w + dist[u];
            dfs(v, u);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int k;
    cin >> k;
    dfs(k, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] << endl;
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
