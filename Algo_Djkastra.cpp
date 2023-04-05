/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

int djkastra(int n, int src, int dst)
{
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;

    dist[src] = 0;
    st.insert({dist[src], src});

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
            }
        }
    }

    cout << "Distance from " << src << " to all other nodes : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dist[i] << endl;
    }
    return dist[dst];
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

    int src, dst;
    cin >> src >> dst;

    int distance = djkastra(n, src, dst);

    cout << distance << endl;
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
