/**
 *    author:  Suresh Kumar
 *    created: 13.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

void solve()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Adj.resize(numberOfNodes, vector<int>());
    bool undirectedGraph = true;
    vector<int> deg(numberOfNodes);

    for (int i = 0; i < numberOfEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
        if (undirectedGraph)
        {
            Adj[to].push_back(from);
        }
        deg[to]++;
    }

    for (int i = 0; i < numberOfNodes; i++)
    {
        if (deg[i] == numberOfNodes - 1)
        {
            cout << "Center of graph is : " << i << endl;
            return;
        }
    }

    cout << "There is no center in this graph.";
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
