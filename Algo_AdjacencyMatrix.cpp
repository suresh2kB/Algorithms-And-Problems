/**
 *    author:  Suresh Kumar
 *    created: 12.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector<vector<int>> Adj;

void solve()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Adj.resize(numberOfNodes, vector<int>(numberOfNodes));
    bool undirectedGraph = false;

    for (int i = 0; i < numberOfEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from][to] = 1;
        if (undirectedGraph)
        {
            Adj[to][from] = 1;
        }
    }

    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
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
