/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;

void floyd_Warshall(int n)
{
    for (int k = 0; k < n; k++)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
                else if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    matrix.resize(n, vector<int>(n, 100000));

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }

    floyd_Warshall(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
