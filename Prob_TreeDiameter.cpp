/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];

void dfs(int u, int p, int cnt, int &node, int &dist)
{
    if (cnt > dist)
    {
        dist = cnt;
        node = u;
    }

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u, cnt + 1, node, dist);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> deg(N, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int node = 0;
    int dist = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            node = i;
            dfs(i, 0, cnt, node, dist);
            break;
        }
    }
    dist = 0;
    dfs(node, 0, 0, node, dist);
    cout << dist << endl;
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
