/**
 *    author:  Suresh Kumar
 **/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool dfs(int u, vector<int> &vis)
{
    vis[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            if (dfs(v, vis))
            {
                return true;
            }
        }
        else if (vis[v] == 1)
        {
            return true;
        }
    }

    vis[u] = 2;

    return false;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);

    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis))
            {
                cout << "We cannot complete all courses" << endl;
                return;
            }
        }
    }
    cout << "We can complete all the courses" << endl;
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
