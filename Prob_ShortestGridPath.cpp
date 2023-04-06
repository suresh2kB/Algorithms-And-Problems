/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<long long> X = {-1, 1, 0, 0};
vector<long long> Y = {0, 0, -1, 1};

long long djkastra(long long n, long long m, vector<vector<long long>> grid)
{
    vector<vector<long long>> dist(n, vector<long long>(m, INT_MAX));
    dist[0][0] = grid[0][0];
    set<vector<long long>> st;
    st.insert({dist[0][0], 0, 0});

    while (!st.empty())
    {
        vector<long long> top = *st.begin();
        long long i = top[1];
        long long j = top[2];
        long long w = top[0];
        st.erase(top);

        for (long long k = 0; k < 4; k++)
        {
            long long x = i + X[k];
            long long y = j + Y[k];

            if (x >= 0 && x < n && y >= 0 && y < m)
            {
                if (w + grid[x][y] < dist[x][y])
                {
                    auto f = st.find({dist[x][y], x, y});
                    if (f != st.end())
                    {
                        st.erase(f);
                    }
                    dist[x][y] = w + grid[x][y];
                    st.insert({dist[x][y], x, y});
                }
            }
        }
    }

    return dist[n - 1][m - 1];
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> grid(n, vector<long long>(m, 0));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    long long ans = djkastra(n, m, grid);

    cout << "Minimum distance is : " << ans << endl;
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
