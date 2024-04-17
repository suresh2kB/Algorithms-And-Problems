/**
 *    author:  Suresh Kumar
 **/

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi


#include <bits/stdc++.h>
using namespace std;

unordered_map<string, multiset<string>> adj;
vector<string> ans;
map<pair<string, string>, int> vis;
map<pair<string, string>, int> tot;
int nodes = 0;
int total = 0;
bool done = false;

void dfs(string u)
{
    if (done)
    {
        return;
    }

    ans.push_back(u);

    for (string v : adj[u])
    {
        if (vis[{u, v}] < tot[{u, v}] && !done)
        {
            vis[{u, v}]++;
            nodes++;
            dfs(v);
            if (nodes == total)
            {
                done = true;
                return;
            }
            nodes--;
            vis[{u, v}]--;
            ans.pop_back();
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        total++;
        string from, to;
        cin >> from >> to;
        adj[from].insert(to);
        adj[to].insert(from);
        vis[{from, to}] = 0;
        tot[{from, to}]++;
    }

    string source = "JFK";
    dfs(source);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
