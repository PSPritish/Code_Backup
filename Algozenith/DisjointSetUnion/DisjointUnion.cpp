#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
class disjointset
{
public:
    int *root, *sz;
    disjointset(int n)
    {
        root = new int[n + 1];
        sz = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x)
    {
        if (root[x] == x)
            return x;
        return root[x] = find(root[x]);
    }
    bool check(int x, int y)
    {
        return find(x) == find(y);
    }
    void merge(int a, int b)
    {
        int x = find(a), y = find(b);
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        if (x != y)
        {
            root[y] = x;
            sz[x] += sz[y];
            sz[y] = 0;
        }
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    disjointset w(n + 1);
    for (int i = 0; i < q; i++)
    {
        int com, x, y;
        cin >> com >> x >> y;
        if (!com)
            w.merge(x, y);
        else
            cout << w.check(x, y) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}