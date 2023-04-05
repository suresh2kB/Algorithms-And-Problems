/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

vector<int> findPath(int n, int src, int dst)
{
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert({dist[src], src});
    vector<int> parent(n, -1);

    while (!st.empty())
    {
        auto it = st.begin();
        int node = it->second;
        int nodeWeight = it->first;
        st.erase(it);

        for (auto nbrPair : adj[node])
        {
            int nbr = nbrPair.first;
            int nbrWeight = nbrPair.second;

            if (nodeWeight + nbrWeight < dist[nbr])
            {
                auto f = st.find({dist[nbr], nbr});
                if (f != st.end())
                {
                    st.erase(f);
                }

                dist[nbr] = nodeWeight + nbrWeight;
                st.insert({dist[nbr], nbr});
                parent[nbr] = node;
            }
        }
    }

    vector<int> path;
    int curr = n - 1;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return path;
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
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> path = findPath(n, 0, n - 1);
    if (path.size() == 0 || path[0] != 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1 << " ";
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
