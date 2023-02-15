/**
 *    author:  Suresh Kumar
 *    created: 15.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

void BFS(int source, int dest, int numberOfNodes)
{
    vector<int> vis(numberOfNodes, 0);
    vector<int> parent(numberOfNodes, -1);
    vector<int> distance(numberOfNodes, 0);
    queue<int> q;
    vis[source] = 1;
    q.push(source);
    parent[source] = source;
    distance[source] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int v : Adj[curr])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
                distance[v] = distance[curr] + 1;
                parent[v] = curr;
            }
        }
    }

    for (int i = 0; i < numberOfNodes; i++)
    {
        cout << "Distance from node " << source << " to " << i << " is : " << distance[i] << endl;
    }

    if (dest != -1)
    {
        cout << "Path from " << dest << " to " << source << " is : ";
        int temp = dest;
        while (temp != source)
        {
            cout << temp << " --> ";
            temp = parent[temp];
        }

        cout << source << endl;
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
    int dest = 4;

    BFS(source, dest, numberOfNodes);
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
