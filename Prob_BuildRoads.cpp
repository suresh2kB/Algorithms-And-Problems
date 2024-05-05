The road network of a state needs to be rebuilt.There are various cities in the state represented by a unique number. You are assigned a job to build the roads.Roads must be built in such a way that all the cities are connected to each other(either directly or indirectly) and the total length of the new roads that has to be built is least.You are provided with the distance between certain pairs of cities.Find out the least possible total length of the roads that need to be laid.

INPUT First line contains an integer k specifying the number of pairs of cities whose inter-city distance is given to you. Next k lines contain 3 space separated integers q1 q2 and d. q1 is city number of first city. q2 is city number of second city. d represents the distance between the two cities.

OUTPUT Print the least possible total length of the roads that need to be laid.

CONSTRAINTS 0 < k <= 10^5 0 < d <= 1000 0 < q1,q2 <= 10^5
    
/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> edges;

long long find(long long u, vector<long long> &parent)
{
    if (parent[u] == -1)
    {
        return u;
    }
    return parent[u] = find(parent[u], parent);
}

void unite(long long u, long long v, vector<long long> &parent, vector<long long> &deg)
{
    long long s1 = find(u, parent);
    long long s2 = find(v, parent);

    if (deg[s1] < deg[s2])
    {
        parent[s1] = s2;
    }
    else if (deg[s2] < deg[s1])
    {
        parent[s2] = s1;
    }
    else
    {
        parent[s1] = s2;
        deg[s2]++;
    }
}
void solve()
{
    long long e;
    cin >> e;
    vector<vector<long long>> arr;
    for (long long i = 0; i < e; i++)
    {
        long long x, y;
        cin >> x >> y;
        arr.push_back({x, y, i});
    }
    sort(arr.begin(), arr.end());
    for (long long i = 1; i < arr.size(); i++)
    {
        edges.push_back({arr[i][0] - arr[i - 1][0], arr[i][2], arr[i - 1][2]});
    }
    for (long long i = 0; i < arr.size(); i++)
    {
        swap(arr[i][0], arr[i][1]);
    }
    sort(arr.begin(), arr.end());
    for (long long i = 1; i < arr.size(); i++)
    {
        edges.push_back({arr[i][0] - arr[i - 1][0], arr[i][2], arr[i - 1][2]});
    }
    sort(edges.begin(), edges.end());

    vector<long long> parent(100001, -1);
    vector<long long> deg(100001, 0);
    long long ans = 0;

    for (long long i = 0; i < edges.size(); i++)
    {
        long long u = edges[i][1];
        long long v = edges[i][2];
        long long w = edges[i][0];
        ;

        if (find(u, parent) != find(v, parent))
        {
            ans += w;
            unite(u, v, parent, deg);
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
