/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int depth[N], par[N];

void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    par[u] = p;

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

int LCA(int u, int v)
{
    if (u == v)
    {
        return u;
    }
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];

    while (diff--)
    {
        u = par[u];
    }

    while (u != v)
    {
        u = par[u];
        v = par[v];
    }
    return u;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is : " << LCA(u, v) << endl;
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
