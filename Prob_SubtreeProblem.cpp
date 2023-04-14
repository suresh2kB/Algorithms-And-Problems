/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int subtreeCount[N];

void dfs(int u, int p)
{
    subtreeCount[u] = 1;

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            subtreeCount[u] += subtreeCount[v];
        }
    }
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

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << subtreeCount[i] << endl;
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
