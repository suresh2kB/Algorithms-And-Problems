/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

int find(int u, vector<int> &parent)
{
    if (parent[u] == -1)
    {
        return u;
    }

    return parent[u] = find(parent[u], parent);
}

void unite(int u, int v, vector<int> &parent, vector<int> &deg)
{
    int s1 = find(u, parent);
    int s2 = find(v, parent);

    if (deg[s1] < deg[s2])
    {
        parent[s1] = s2;
    }
    else if (deg[s2] < deg[s1])
    {
        parent[s2] = s1;
    }
    else
    {
        parent[s1] = s2;
        deg[s2]++;
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // u--;
        // v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n, -1);
    vector<int> deg(n, 0);
    int ans = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][1];
        int v = edges[i][2];
        int w = edges[i][0];
        int s1 = find(u, parent);
        int s2 = find(v, parent);

        if (s1 != s2)
        {
            ans += w;
            unite(u, v, parent, deg);
        }
    }
    cout << ans << endl;
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
