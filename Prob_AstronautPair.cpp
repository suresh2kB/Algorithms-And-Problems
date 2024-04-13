/**
 *    author:  Suresh Kumar
 **/

SpecialX has launched a special spacecraft program that is aimed at sending people into space. The spacecraft is designed to carry only two astronauts at a time. Melon Musk has an idea to sort things out and select who goes in which trip. He wants to choose the two astronauts from different countries. You will be given a list of pairs of astronaut IDs. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries he can choose from.

Input Format

The first line contains two integers N and P, the number of astronauts and the number of pairs. Each of the next P lines contains 2 space-separated integers denoting astronaut IDs of two who share the same nationality.

Constraints

1 ≤ N ≤ 25,000
1 ≤ P ≤ 25,000
Output Format

An integer A that denotes the number of ways to choose a pair of astronauts from different coutries.

Sample Input 0

5 3
0 1
2 3
0 4
Sample Output 0

6
Explanation 0

Persons numbered [0,1,4] belong to one country, and those numbered [2,3] belong to another. Elon has 6 ways of choosing a pair: [0,2] , [0,3] , [1,2] , [1,3] , [4,2] , [4,3]

Sample Input 1

4 1
0 2
Sample Output 1

5
Explanation 1

Persons numbered [0,2] belong to the same country, but persons 1 and 3 don't share countries with anyone else. Elon has 5 ways of choosing a pair: [0,1] , [0,3] , [1,2] , [1,3] , [2,3]

    
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Adj;

int dfs(int u, vector<int> &vis)
{
    vis[u] = 1;

    int curr = 1;

    for (int v : Adj[u])
    {
        if (!vis[v])
        {
            curr += dfs(v, vis);
        }
    }

    return curr;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    Adj.clear();
    Adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    vector<int> arr;

    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int curr = dfs(i, vis);
            arr.push_back(curr);
        }
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            ans += (arr[i] * arr[j]);
        }
    }
    cout << ans << endl;
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
