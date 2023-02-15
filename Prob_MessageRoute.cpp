/**
 *    author:  Suresh Kumar
 *    created: 15.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

void shortestPath(int source, int dest, int numberOfNodes)
{

    vector<int> vis(numberOfNodes);
    vector<int> distance(numberOfNodes, INT_MAX);
    vector<int> parent(numberOfNodes, -1);
    queue<int> q;
    q.push(source);
    parent[source] = source;
    distance[source] = 0;
    vis[source] = 1;

    while (!q.empty())
    {
        int u = q.front();
        // cout << u << " ";
        q.pop();

        for (int v : Adj[u])
        {
            if (!vis[v])
            {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    if (distance[dest] == INT_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        cout << distance[dest] + 1 << endl;
        vector<int> path;
        int temp = dest;

        while (temp != source)
        {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] + 1 << " ";
        }
        cout << endl;
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
        from--;
        to--;
        Adj[from].push_back(to);
        if (undirectedGraph)
        {
            Adj[to].push_back(from);
        }
    }

    int source = 0, dest = numberOfNodes - 1;

    shortestPath(source, dest, numberOfNodes);
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
