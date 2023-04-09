/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> adj;
vector<vector<long long>> grid;

void djkastra(long long u, long long n, long long L)
{
    vector<long long> steps(n, LONG_LONG_MAX);
    vector<long long> fuel(n, 0);
    steps[u] = 0;
    fuel[u] = L;
    set<vector<long long>> st;

    st.insert({steps[u], fuel[u], u});

    while (!st.empty())
    {
        auto top = *st.begin();
        long long step = top[0];
        long long rem = top[1];
        long long node = top[2];

        st.erase(top);

        for (auto it : adj[node])
        {
            long long v = it.first;
            long long weight = it.second;
            long long trem = rem;

            long long req_step = step;
            if (rem < weight)
            {
                req_step++;
                trem = (L - weight);
            }
            else
            {
                trem = trem - weight;
            }
            if (req_step < steps[v])
            {
                auto f = st.find({steps[v], fuel[v], v});
                if (f != st.end())
                {
                    st.erase(f);
                }
                steps[v] = req_step;
                fuel[v] = trem;
                st.insert({steps[v], fuel[v], v});
            }
            else if (req_step == steps[v])
            {
                if (trem > fuel[v])
                {
                    auto f = st.find({steps[v], fuel[v], v});
                    if (f != st.end())
                    {
                        st.erase(f);
                    }
                    fuel[v] = trem;
                    st.insert({steps[v], fuel[v], v});
                }
            }
        }
    }

    for (long long i = 0; i < n; i++)
    {
        grid[u][i] = steps[i];
    }
}
void solve()
{
    long long n, m, l;
    cin >> n >> m >> l;
    adj.resize(n);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    grid.resize(n, vector<long long>(n, LONG_LONG_MAX));

    for (long long i = 0; i < n; i++)
    {
        djkastra(i, n, l);
    }

    // for (long long i = 0; i < n; i++)
    // {
    //     for (long long j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    long long q;
    cin >> q;
    while (q--)
    {
        long long u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << (grid[u][v] == LONG_LONG_MAX ? -1 : grid[u][v]) << endl;
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
