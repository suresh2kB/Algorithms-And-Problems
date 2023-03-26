/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

int find(int u, vector<int> &parent)
{
    if (parent[u] == -1)
    {
        return u;
    }

    return parent[u] = find(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &deg)
{
    int s1 = find(s1, parent);
    int s2 = find(s2, parent);

    if (s1 == s2)
    {
        cout << "This is not a forest" << endl;
        return;
    }
    if (deg[s1] < deg[s2])
    {
        parent[s1] = s2;
    }
    else if (deg[s2] < deg[s1])
    {
        parent[s2] = s1;
    }
    else
    {
        deg[s1]++;
        parent[s2] = s1;
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);
    vector<int> parent(n, -1);
    vector<int> deg(n, 0);
    bool found = false;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        int s1 = find(u, parent);
        int s2 = find(v, parent);

        if (s1 == s2)
        {
            found = true;
        }
        else
        {
            unionSet(u, v, parent, deg);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == -1)
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        found = true;
    }

    if (found)
    {
        cout << "This is not a Forest." << endl;
    }
    else
    {
        cout << "This is a Forest." << endl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
