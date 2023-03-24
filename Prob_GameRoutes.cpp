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
