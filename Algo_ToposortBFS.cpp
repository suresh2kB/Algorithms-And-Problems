/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

void solve()
{
    // For this one we already consider that graph does not contiain a cycle.
    int V, E;
    cin >> V >> E;
    adj.resize(V);
    vector<int> indeg(V, 0);
    vector<int> vis(V, 0);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    cout << "Topological order of the nodes : ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int v : adj[node])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
