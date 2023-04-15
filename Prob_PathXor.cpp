/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 200001, M = 25;
vector<int> adj[N];
int par[N][M], depth[N], ans[N];
int a[N];

void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    ans[u] = (ans[p] xor a[u]);
    par[u][0] = p;

    for (int j = 1; j < M; j++)
    {
        par[u][j] = par[par[u][j - 1]][j - 1];
    }

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

    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            u = par[u][j];
        }
    }

    for (int j = M - 1; j >= 0; j--)
    {
        if (par[u][j] != par[v][j])
        {
            u = par[u][j];
            v = par[v][j];
        }
    }

    if (u == v)
    {
        return u;
    }
    return par[u][0];
}

int findXor(int u, int v)
{
    int lca = LCA(u, v);
    int xor_u = ans[u];
    int xor_v = ans[v];
    int xor_lca = ans[lca];

    int curr = (xor_u xor xor_v);
    curr = (curr xor a[lca]);
    return curr;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

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
        cout << findXor(u, v) << endl;
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
