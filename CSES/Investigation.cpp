#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<pair<int, int>>> back_edge(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        back_edge[b].push_back({a, c});
    }
    vector<int> dist(n + 1, 1e18);
    vector<int> num(n + 1, 0);
    vector<int> minf(n + 1, 1e18);
    vector<int> maxf(n + 1, -1e18);
    vector<int> vis(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    num[1] = 1;
    minf[1] = 0;
    maxf[1] = 0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                num[v] = num[u];
                minf[v] = minf[u] + 1;
                maxf[v] = maxf[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                num[v] += num[u];
                num[v] %= 1000000007;
                minf[v] = min(minf[v], minf[u] + 1);
                maxf[v] = max(maxf[v], maxf[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n];
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