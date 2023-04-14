/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
vector<int> adj[N];
int tme = 0;
int tin[N], tout[N], flat[N], height[N];

void eularCycle(int u, int p, int h)
{
    tin[u] = ++tme;
    height[u] = h;

    for (int v : adj[u])
    {
        if (v != p)
        {
            eularCycle(v, u, h + 1);
        }
    }
    tout[u] = tme;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    eularCycle(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        flat[tin[i]] = i;
    }
    vector<vector<int>> depth(N);

    for (int i = 1; i <= n; i++)
    {
        depth[height[flat[i]]].push_back(i);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, d;
        cin >> u >> d;
        cout << upper_bound(depth[d].begin(), depth[d].end(), tout[u]) - lower_bound(depth[d].begin(), depth[d].end(), tin[u]) << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
