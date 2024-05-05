We have a rooted tree with 
N vertices, numbered 
1,2,…,N.

Vertex 
1 is the root, and the parent of Vertex 
i(2≤i≤N) is Vertex 
P 
i
​
 .

You are given 
Q queries. In the 
i-th query 
(1≤i≤Q), given integers 
U 
i
​
  and 
D 
i
​
 , find the number of vertices 
u that satisfy all of the following conditions:

Vertex 
U 
i
​
  is in the shortest path from 
u to the root (including the endpoints).
There are exactly 
D 
i
​
  edges in the shortest path from 
u to the root.
Constraints
2≤N≤2×10 
5
 
1≤P 
i
​
 <i
1≤Q≤2×10 
5
 
1≤U 
i
​
 ≤N
0≤D 
i
​
 ≤N−1
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N
P 
2
​
  
P 
3
​
  
… 
P 
N
​
 
Q
U 
1
​
  
D 
1
​
 
U 
2
​
  
D 
2
​
 
⋮
U 
Q
​
  
D 
Q
​
 
Output
Print 
Q lines. The 
i-th line should contain the response to the 
i-th query.

Sample Input 1
Copy
7
1 1 2 2 4 2
4
1 2
7 2
4 1
5 5
Sample Output 1
Copy
3
1
0
0
In the 
1-st query, Vertices 
4, 
5, and 
7 satisfy the conditions. In the 
2-nd query, only Vertices 
7 satisfies the conditions. In the 
3-rd and 
4-th queries, no vertice satisfies the conditions.



    
/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
vector<int> adj[N];
int tme = 0;
int tin[N], tout[N], flat[N], height[N];

void eularCycle(int u, int p, int h)
{
    tin[u] = ++tme;
    height[u] = h;

    for (int v : adj[u])
    {
        if (v != p)
        {
            eularCycle(v, u, h + 1);
        }
    }
    tout[u] = tme;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    eularCycle(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        flat[tin[i]] = i;
    }
    vector<vector<int>> depth(N);

    for (int i = 1; i <= n; i++)
    {
        depth[height[flat[i]]].push_back(i);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, d;
        cin >> u >> d;
        cout << upper_bound(depth[d].begin(), depth[d].end(), tout[u]) - lower_bound(depth[d].begin(), depth[d].end(), tin[u]) << endl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
