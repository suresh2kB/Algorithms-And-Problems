/**
 *    author:  Suresh Kumar
 *    created: 15.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

void BFS(int source, int numberOfNodes)
{
    vector<int> vis(numberOfNodes, 0);
    queue<int> q;
    vis[source] = 1;
    q.push(source);

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        for (int v : Adj[curr])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Adj.resize(numberOfNodes);
    bool undirectedGraph = true;

    for (int i = 0; i < numberOfEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
        if (undirectedGraph)
        {
            Adj[to].push_back(from);
        }
    }

    int source = 1;

    BFS(source, numberOfNodes);
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
