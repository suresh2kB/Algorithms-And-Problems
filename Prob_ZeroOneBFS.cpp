/**
 *    author:  Suresh Kumar
 **/

Question: Find the distance from src to every node in the graph.
    
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

void solve()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    deque<int> dq;
    dq.push_back(src);
    vector<int> vis(n, 0);
    vector<int> dist(n, INT_MAX);
    vis[src] = 1;
    dist[src] = 0;

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        vis[u] = 1;
        // cout << u << " : ";

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!vis[v])
            {
                if (w == 1)
                {
                    dist[v] = dist[u] + 1;
                    dq.push_back(v);
                }
                else
                {
                    dist[v] = dist[u];
                    dq.push_front(v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
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
