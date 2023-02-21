/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool cycleDetection(int u, vector<int> &vis, int p = -1)
{
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            bool nbrFoundCycle = cycleDetection(v, vis, u);
            if (nbrFoundCycle)
            {
                return true;
            }
        }
        else if (v != p)
        {
            return true;
        }
    }

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
        adj[to].push_back(from);
    }
    vector<int> vis(n);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (cycleDetection(i, vis))
            {
                cout << "There is atleast one cycle in the graph" << endl;
                return;
            }
        }
    }

    cout << "There is no cycle in the graph" << endl;
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
