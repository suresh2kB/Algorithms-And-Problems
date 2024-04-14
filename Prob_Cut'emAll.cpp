/**
 *    author:  Suresh Kumar
 **/

You're given a tree with n vertices.

Your task is to determine the maximum possible number of edges that can be removed in such a way that all the remaining connected components will have even size.

Input
The first line contains an integer n (1≤n≤105) denoting the size of the tree.

The next n−1 lines contain two integers u, v (1≤u,v≤n) each, describing the vertices connected by the i-th edge.

It's guaranteed that the given edges form a tree.

Output
Output a single integer k
 — the maximum number of edges that can be removed to leave all connected components with even size, or −1
 if it is impossible to remove edges in order to satisfy this property.

Examples
input
4
2 4
4 1
3 1
output
1
input
3
1 2
1 3
output
-1
input
10
7 1
8 4
8 10
4 7
6 5
9 3
3 5
2 10
2 5
output
4
input
2
1 2
output
0
    
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
