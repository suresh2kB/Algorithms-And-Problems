/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, multiset<string>> adj;
vector<string> ans;
map<pair<string, string>, int> vis;
map<pair<string, string>, int> tot;
int nodes = 0;
int total = 0;
bool done = false;

void dfs(string u)
{
    if (done)
    {
        return;
    }

    ans.push_back(u);

    for (string v : adj[u])
    {
        if (vis[{u, v}] < tot[{u, v}] && !done)
        {
            vis[{u, v}]++;
            nodes++;
            dfs(v);
            if (nodes == total)
            {
                done = true;
                return;
            }
            nodes--;
            vis[{u, v}]--;
            ans.pop_back();
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        total++;
        string from, to;
        cin >> from >> to;
        adj[from].insert(to);
        adj[to].insert(from);
        vis[{from, to}] = 0;
        tot[{from, to}]++;
    }

    string source = "JFK";
    dfs(source);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
