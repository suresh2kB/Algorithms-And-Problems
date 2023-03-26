/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

int find(int u, vector<int> &parent)
{
    if (parent[u] == -1)
    {
        return u;
    }
    return parent[u] = find(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &deg)
{
    int s1 = find(u, parent);
    int s2 = find(v, parent);

    if (deg[s1] > deg[s2])
    {
        parent[s2] = s1;
    }
    else if (deg[s2] > deg[s1])
    {
        parent[s1] = s2;
    }
    else
    {
        parent[s2] = s1;
        deg[s1]++;
    }
}
void solve()
{
    // Cycle detection using Disjoint Set Union.
    int n, e;
    cin >> n >> e;
    vector<int> parent(n, -1);
    vector<int> deg(n, 0);
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        int s1 = find(u, parent);
        int s2 = find(v, parent);

        if (s1 != s2)
        {
            unionSet(s1, s2, parent, deg);
        }
        else
        {
            cout << "Cycle present between nodes " << u << " and " << v << endl;
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
