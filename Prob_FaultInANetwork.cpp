/**
 *    author:  Suresh Kumar
 **/

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

    
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int vis[N], disc[N], low[N];
int tme = 1;
vector<pair<int, int>> bridges;

void dfs(int u, int p)
{
    vis[u] = 1;

    disc[u] = low[u] = tme;
    tme++;
    int child = 0;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, u);
            child++;
            low[u] = min(low[u], low[v]);

            // Bridges
            if (disc[u] < low[v])
            {
                bridges.push_back({u, v});
            }
        }
        else if (v != p)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1);
        }
    }

    for (int i = 0; i < bridges.size(); i++)
    {
        cout << bridges[i].first << " " << bridges[i].second << endl;
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
