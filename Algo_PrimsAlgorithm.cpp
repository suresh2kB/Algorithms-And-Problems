/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

int primsAlgorithm(int n)
{
    vector<int> vis(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int ans = 0;
    pq.push({0, 0});

    vector<pair<int, int>> pairs;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (vis[u] == 1)
        {
            continue;
        }
        ans += weight;
        vis[u] = 1;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!vis[v])
            {
                pq.push({w, v});
            }
        }
    }

    return ans;
}
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

    int ans = primsAlgorithm(n);

    cout << "Minimum spanning tree answer is : " << ans << endl;
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
