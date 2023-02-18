/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<int>> Adj;

void dfs(int u, vector<int> &vis)
{
    cout << u << " ";
    vis[u] = 1;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            dfs(v, vis);
        }
    }
}
void solve()
{
    int numberOfNodes;
    cin >> numberOfNodes;
    Adj.resize(numberOfNodes + 1);
    int numberOfEdges;
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
        Adj[to].push_back(from);
    }
    vector<int> vis(numberOfNodes + 1);

    dfs(0, vis);
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
