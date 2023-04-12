/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int vis[N], dsc[N], low[N];
vector<pair<int, int>> bridges;
set<int> articulation_point;
int root = 1, tme = 0;

void dfs(int u, int p)
{
    vis[u] = 1;
    dsc[u] = low[u] = tme;
    tme++;
    int childs = 0;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            childs++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // Bridges.
            if (low[v] > dsc[u])
            {
                bridges.push_back({u, v});
            }

            // Articulation point.
            if (p != -1 && low[v] >= dsc[u])
            {
                articulation_point.insert(u);
            }
        }
        else if (v != p)
        {
            low[u] = min(low[u], dsc[v]);
        }
    }

    if (p == -1 && childs > 1)
    {
        articulation_point.insert(u);
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
            root = i;
            dfs(i, -1);
        }
    }

    cout << "Bridges in the graph : " << endl;

    for (int i = 0; i < bridges.size(); i++)
    {
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
    cout << endl;
    cout << "Articulation points : " << endl;
    for (auto it = articulation_point.begin(); it != articulation_point.end(); it++)
    {
        cout << *it << " ";
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
