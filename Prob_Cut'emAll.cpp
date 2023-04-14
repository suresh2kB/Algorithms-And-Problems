/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int subtreeSum[N];
int ans = 0;

void dfs(int u, int p)
{
    subtreeSum[u] = 1;

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            subtreeSum[u] += subtreeSum[v];
        }
    }
    // cout << u << " " << subtreeSum[u] << endl;
    if (subtreeSum[u] % 2 == 0)
    {
        ans++;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> deg(N, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            dfs(i, 0);
            break;
        }
    }

    cout << ans - 1 << endl;
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
