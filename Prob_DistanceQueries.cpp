/**
 *    author:  Suresh Kumar
 **/

You are given a tree consisting of n nodes.
Your task is to process q queries of the form: what is the distance between nodes a and b?
Input
The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are q lines describing the queries. Each line contains two integer a and b: what is the distance between nodes a and b?
Output
Print q integers: the answer to each query.
Constraints

1 \le n, q \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4

Output:
1
3
2
    
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, M = 20;
vector<int> adj[N];
int par[N][M], depth[N];

void dfs(int u, int p)
{
    depth[u] = depth[p] + 1;
    par[u][0] = p;

    for (int j = 1; j < M; j++)
    {
        par[u][j] = par[par[u][j - 1]][j - 1];
    }

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

int LCA(int u, int v)
{
    if (u == v)
    {
        return u;
    }
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];

    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            u = par[u][j];
        }
    }

    for (int j = M - 1; j >= 0; j--)
    {
        if (par[u][j] != par[v][j])
        {
            u = par[u][j];
            v = par[v][j];
        }
    }

    if (u == v)
    {
        return u;
    }
    return par[u][0];
}

int distance(int u, int v)
{
    int lca = LCA(u, v);

    return depth[u] + depth[v] - depth[lca] * 2;
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

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << distance(u, v) << endl;
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
