#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<int> dist(n + 1, LLONG_MIN);
    vector<bool> inCycle(n + 1, false);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }

    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &e : edges)
        {
            auto &[a, b, c] = e;
            if (dist[a] == LLONG_MIN)
                continue;
            dist[b] = max(dist[b], dist[a] + c);
        }
    }

    // detect cycle
    for (auto &e : edges)
    {
        auto &[a, b, c] = e;
        if (dist[a] != LLONG_MIN && dist[b] < dist[a] + c)
        {
            inCycle[a] = true;
        }
    }

    // propagate cycle info
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inCycle[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!inCycle[v])
            {
                inCycle[v] = true;
                q.push(v);
            }
        }
    }
    if (inCycle[n])
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
