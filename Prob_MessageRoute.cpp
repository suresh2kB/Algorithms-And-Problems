/**
 *    author:  Suresh Kumar
 *    created: 15.02.2023
 **/

Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

    
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
