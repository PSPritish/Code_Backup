#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, (-1) * c});
    }
    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;
            if (dist[a] != LLONG_MAX and dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }
    for (auto e : edges)
    {
        int a, b, w;
        tie(a, b, w) = e;
        if (dist[a] != LLONG_MAX and dist[a] + w < dist[b])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << -1 * dist[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}
