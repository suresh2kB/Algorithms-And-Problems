/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int a[N], seg[4 * N];

void construct(int l, int r, int index)
{
    if (l == r)
    {
        seg[index] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    construct(l, mid, 2 * index + 1);
    construct(mid + 1, r, 2 * index + 2);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

void update(int l, int r, int index, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        seg[index] = val;
        a[l] = val;
        return;
    }

    int mid = l + (r - l) / 2;
    update(l, mid, 2 * index + 1, pos, val);
    update(mid + 1, r, 2 * index + 2, pos, val);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

int rangeMin(int l, int r, int index, int rl, int rr)
{
    if (l > rr || r < rl)
    {
        return INT_MAX;
    }
    if (l >= rl && r <= rr)
    {
        return seg[index];
    }

    int mid = l + (r - l) / 2;
    return min(rangeMin(l, mid, 2 * index + 1, rl, rr), rangeMin(mid + 1, r, 2 * index + 2, rl, rr));
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    construct(0, n - 1, 0);
    update(0, n - 1, 0, 1, -9);
    update(0, n - 1, 0, 2, 9);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << "Range minimum for " << l << " to " << r << " is : " << rangeMin(0, n - 1, 0, l, r) << endl;
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
