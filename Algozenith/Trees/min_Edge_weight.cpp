#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
class dsu
{
    vector<int> parent;
    vector<int> rank;

public:
    dsu(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i{0}; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    int merge(int x, int y, int w)
    {
        x = find(x);
        y = find(y);
        if (rank[x] > rank[y])
            swap(x, y); // x is always smaller
        parent[x] = y;
        int ans = rank[x] * rank[y] * w;
        rank[y] += rank[x];
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> a;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        a.push_back({w, {x, y}});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    dsu d(n + 1);
    for (int i{0}; i < n - 1; i++)
    {
        ans += d.merge(a[i].second.first, a[i].second.second, a[i].first);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;

    while (a--)
        solve();
}