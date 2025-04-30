#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int a[200200];
int t[800800]; // 4 times the size of the array

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = a[l];
        return;
    }
    int mid = (r + l) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = t[index * 2] + t[index * 2 + 1]; // sum of the left and right child
}
void update(int index, int l, int r, int pos, int val)
{
    if (pos < l or pos > r)
        return; // out of bounds
    if (l == r)
    {
        a[l] = val;
        t[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val);
    update(2 * index + 1, mid + 1, r, pos, val);
    t[index] = t[index * 2] + t[index * 2 + 1];
}
int query(int index, int l, int r, int lq, int rq)
{
    if (l > rq or r < lq)
        return 0;
    if (lq <= l and r <= rq)
        return t[index];
    int mid = (l + r) / 2;
    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int t, b, c;
        cin >> t >> b >> c;
        if (t == 1)
        {
            update(1, 0, n - 1, b - 1, c);
        }
        else
        {
            cout << query(1, 0, n - 1, b - 1, c - 1) << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}