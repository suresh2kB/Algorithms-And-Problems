A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?
Input
The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,\dots,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.
Output
Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 10^9+7.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 5
1 2
2 4
1 3
3 4
1 4

Output:
3
 
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Adj;
vector<int> vis;
vector<int> ans;
const long MOD = 1000000007;
 
int dfs(int u, int n)
{
    if (vis[u])
    {
        return ans[u];
    }
    vis[u] = 1;
    // cout << u << " ";
    if (u == n)
    {
        return ans[u] = 1;
    }
 
    long long curr = 0;
    for (int v : Adj[u])
    {
        curr += (dfs(v, n));
        curr = curr % MOD;
    }
    return ans[u] = curr % MOD;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vis.resize(n, 0);
    ans.resize(n, 0);
    Adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Adj[u].push_back(v);
    }
    long long res = 0;
    res += (dfs(0, n - 1) % MOD);
 
    cout << res % MOD << endl;
    return 0;
}
