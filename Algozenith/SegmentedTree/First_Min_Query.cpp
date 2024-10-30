#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

int tree[4 * N];
int A[N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        A[start] -= val;
        tree[node] = A[start];
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int x)
{
    if (tree[node] < x)
        return -1;
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (tree[2 * node] >= x)
        return query(2 * node, start, mid, x);
    return query(2 * node + 1, mid + 1, end, x);
}

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    build(1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int ans = query(1, 0, n - 1, x);
        if (ans >= 0)
            update(1, 0, n - 1, ans, x);
        cout << ans + 1 << " ";
    }
    cout << "\n";
    return 0;
}
// Time complexity: O(nlogn) for building the segment tree and O(qlogn) for each query.