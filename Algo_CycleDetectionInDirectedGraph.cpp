/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool foundCycleInDirectedGraph(int u, vector<int> &vis)
{
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            bool nbrFoundCycle = foundCycleInDirectedGraph(v, vis);
            if (nbrFoundCycle)
            {
                return true;
            }
        }
        else if (vis[v] == 1)
        {
            return true;
        }
    }

    vis[u] = 2;

    return false;
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
    }
    vector<int> vis(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (foundCycleInDirectedGraph(i, vis))
            {
                cout << "There is atleat one cycle present in the graph" << endl;
                return;
            }
        }
    }

    cout << "There is no cycle present in the graph" << endl;
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
