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
    Adj.resize(numberOfNodes, vector<int>(numberOfNodes));
    bool undirectedGraph = true;
    vector<int> deg(numberOfNodes);

    for (int i = 0; i < numberOfEdges; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from][to] = 1;
        Adj[to][from] = 1;

        deg[to]++;
        deg[from]++;
    }

    int networkRank = 0;
    for (int i = 0; i < numberOfNodes; i++)
    {
        for (int j = 0; j < numberOfNodes; j++)
        {
            if (i != j)
            {
                if (deg[i] + deg[j] - Adj[i][j] > networkRank)
                {
                    networkRank = deg[i] + deg[j] - Adj[i][j];
                }
            }
        }
    }

    cout << "Network Rank is : " << networkRank << endl;
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
