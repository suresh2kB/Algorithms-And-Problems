/**
 *    author:  Suresh Kumar
 **/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.


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
        cout << LCA(u, v) << endl;
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
