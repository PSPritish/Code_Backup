#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
class DSU
{
    vector<int> rank;
    vector<pair<int, int>> parent;

public:
    DSU(int n)
    {
        rank.assign(n + 1, 0);
        parent.resize(n + 1);
        for (int i{0}; i <= n; i++)
        {
            rank[i] = 1;
            parent[i] = {i, 0};
        }
    }
    pair<int, int> find(int x)
    {
        if (parent[x].first == x)
            return parent[x];
        pair<int, int> temp = find(parent[x].first);
        return parent[x] = {temp.first, temp.second + parent[x].second};
    }

    void relate(int x, int y, int w)
    {
        auto px = find(x);
        auto py = find(y);
        if (px.first == py.first)
            return;
        if (rank[px.first] > rank[py.first])
        {
            swap(px, py);
            w = -w;
        }
        parent[px.first] = {py.first, w + py.second - px.second};
        rank[px.first] += rank[py.first];
    }
    void dist(int x, int y)
    {
        pair<int, int> px = find(x);
        pair<int, int> py = find(y);
        if (px.first != py.first)
            cout << "?" << endl;
        else
            cout << (px.second - py.second) << endl;
    }
};
void solve()
{
    int n;
    cin >> n;
    DSU dsu(n);
    int q;
    cin >> q;
    while (q--)
    {
        int com;
        cin >> com;
        if (com)
        {
            int x, y;
            cin >> x >> y;
            dsu.dist(x, y);
        }
        else
        {
            int x, y, w;
            cin >> x >> y >> w;
            dsu.relate(x, y, w);
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