/**
 *    author:  Suresh Kumar
 **/
Question: Print cycle in a graph.
    
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int vis[N], par[N];

void dfs(int u, int p)
{
    vis[u] = 1;
    par[u] = p;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, u);
        }
        else if (v != p && vis[v] == 1)
        {
            int x = u;
            int y = v;
            while (x != y)
            {
                cout << x << " ";
                x = par[x];
            }
            cout << x << endl;
            // exit(0);
        }
    }
    vis[u] = 2;
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
