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

    for (int i = 0; i < numberOfNodes; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < Adj[i].size(); j++)
        {
            cout << Adj[i][j] << " ";
        }
        cout << endl;
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
