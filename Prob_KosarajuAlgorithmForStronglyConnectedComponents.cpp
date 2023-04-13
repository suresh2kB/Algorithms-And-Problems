/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N], radj[N];
int vis[N], color[N];
vector<int> order;

void dfs1(int u)
{
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int comp)
{
    vis[u] = 1;
    color[u] = comp;

    for (int v : radj[u])
    {
        if (!vis[v])
        {
            dfs2(v, comp);
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }

    reverse(order.begin(), order.end());
    for (auto x : order)
    {
        cout << x << " ";
    }
    cout << endl;
    memset(vis, 0, sizeof(vis));

    int comp = 1;
    for (int i = 0; i < order.size(); i++)
    {
        if (!vis[order[i]])
        {
            dfs2(order[i], comp++);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->" << color[i] << endl;
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
