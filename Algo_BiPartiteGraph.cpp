/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool biPartiteGraph(int u, int p, int color, vector<int> &vis)
{
    vis[u] = color;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            bool subSol = biPartiteGraph(v, u, 3 - color, vis);
            if (subSol == false)
            {
                return false;
            }
        }
        else if (v != p && color == vis[v])
        {
            return false;
        }
    }

    return true;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int> vis(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (!biPartiteGraph(i, -1, 1, vis))
            {
                cout << "The graph is not bi-partite" << endl;
                return;
            }
        }
    }

    cout << "We can divide graph in two separate parts" << endl;
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
