/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
int tin[N], tout[N];
int tme = 0;

void eularCycle1(int u, int p) // Length = 2*number of nodes.
{
    cout << u << " ";

    for (int v : adj[u])
    {
        if (v != p)
        {
            eularCycle1(v, u);
        }
    }
    cout << u << " ";
}

void eularCycle2(int u, int p) // Length = number of nodes + number of edges.
{
    cout << u << " ";

    for (int v : adj[u])
    {
        if (v != p)
        {
            eularCycle2(v, u);
            cout << u << " ";
        }
    }
}

void eularCycle3(int u, int p) // Length = number of nodes + number of edges.
{
    tin[u] = ++tme;
    for (int v : adj[u])
    {
        if (v != p)
        {
            eularCycle3(v, u);
        }
    }

    tout[u] = tme;
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

    // eularCycle1(1, 0);
    // cout << endl;
    // eularCycle2(1, 0);
    tme = 0;
    eularCycle3(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << tin[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << tout[i] << " ";
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
