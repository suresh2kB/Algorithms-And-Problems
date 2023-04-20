/**
 *    author:  Suresh Kumar
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int a[N], seg[4 * N];

void construct(int l, int r, int index)
{
    if (l > r)
    {
        return;
    }
    if (l == r)
    {
        seg[index] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    construct(l, mid, 2 * index + 1);
    construct(mid + 1, r, 2 * index + 2);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int getRangeSum(int l, int r, int index, int rl, int rr)
{
    if (rl > r || rr < l)
    {
        return 0;
    }

    if (l >= rl && r <= rr)
    {
        return seg[index];
    }

    int mid = l + (r - l) / 2;
    return getRangeSum(l, mid, 2 * index + 1, rl, rr) +
           getRangeSum(mid + 1, r, 2 * index + 2, rl, rr);
}

void update(int l, int r, int index, int pos, int val)
{
    if (l > r)
    {
        return;
    }
    if (pos < l || pos > r)
    {
        return;
    }

    seg[index] += val;
    if (l != r)
    {
        int mid = l + (r - l) / 2;
        update(l, mid, 2 * index + 1, pos, val);
        update(mid + 1, r, 2 * index + 2, pos, val);
    }
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
    for (int i = 0; i < 4 * n; i++)
    {
        cout << seg[i] << " ";
    }
    cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << "Range sum from " << l << " to " << r << " : " << getRangeSum(0, n - 1, 0, l, r) << endl;
        int index, val;
        cin >> index >> val;
        int num = val;
        val = val - a[index];
        update(0, n - 1, 0, index, val);
        a[index] = num;
        cout << "Range sum from " << l << " to " << r << " : " << getRangeSum(0, n - 1, 0, l, r) << endl;
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
