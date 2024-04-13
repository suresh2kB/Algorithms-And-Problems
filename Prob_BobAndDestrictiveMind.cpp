/**
 *    author:  Suresh Kumar
 **/

Problem
Rhezo has bought a graph with N nodes and M edges. He has a destructive mind and often deletes some nodes(and of course its edges to other nodes of the graph).

He will ask you Q queries. Each query is denoted by an integer X, meaning that he will delete the node X. Since he has a destructive mind, he gets satisfied if the the new graph with deleted node has more number of connected components than the original graph.

If satisfied, he wants you to print "Satisfied"(without quotes) and the number of edges that were removed when deleting node X, else print "Not Satisfied"(without quotes). All queries are different, and the original graph is restored after each query.

Input:

First line contains N and M as described in the problem statement. Each of the next M lines contain 2 integers 
 and 
, meaning that there is an edge between node A and node B. Next line contains a single integer Q, denoting the number of queries. Each of the next Q lines contain a single integer X as described in the problem statement.

Output:

For each of the Q queries, if Rhezo is satisfied(that is the number of connected components of the new graph has increased), print "Satisfied"(without quotes), and the number of edges that will be deleted after a space. Else print "Not Satisfied".


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int vis[N], disc[N], low[N];
int tme = 1;
set<int> articulationPoint;

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

            // Articulation Point.
            if (p != -1 && disc[u] <= low[v])
            {
                articulationPoint.insert(u);
            }
        }
        else if (v != p)
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (p == -1 && child > 1)
    {
        articulationPoint.insert(u);
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

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        auto it = articulationPoint.find(x);
        if (it != articulationPoint.end())
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
