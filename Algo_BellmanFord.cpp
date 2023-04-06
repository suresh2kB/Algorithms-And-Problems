/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;

void bellmanFord(int n, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int cnt = 0; cnt < n - 1; cnt++)
    {

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "The contains a negative weight cycle" << endl;
            return;
        }
    }

    cout << "Distance from " << src << " to all other nodes : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
void solve()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;
    bellmanFord(n, src);
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
