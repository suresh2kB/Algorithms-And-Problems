/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int vis[N], disc[N], low[N];
int tme = 1;
set<int> articulationPoint;

void dfs(int u, int p)
{
    vis[u] = 1;

    disc[u] = low[u] = tme;
    tme++;
    int child = 0;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, u);
            child++;
            low[u] = min(low[u], low[v]);

            // Articulation Point.
            if (p != -1 && disc[u] <= low[v])
            {
                articulationPoint.insert(u);
            }
        }
        else if (v != p)
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (p == -1 && child > 1)
    {
        articulationPoint.insert(u);
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
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        auto it = articulationPoint.find(x);
        if (it != articulationPoint.end())
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
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
