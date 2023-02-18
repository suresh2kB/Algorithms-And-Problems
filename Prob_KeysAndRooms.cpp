/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<int>> Adj;

void keysAndRooms(int u, vector<int> &vis)
{
    vis[u] = 1;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            keysAndRooms(v, vis);
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

    keysAndRooms(0, vis);
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (!vis[i])
        {
            cout << "We cannot unlock all rooms" << endl;
            return;
        }
    }

    cout << "All rooms are unlocked" << endl;
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
