#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int n, m;

struct comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
vector<int> dijkstra(int node, vector<pair<int, int>> adj[])
{
    vector<int> dist(n + 1, 1e18);
    dist[node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({node, 0});
    vector<int> vis(n + 1, 0);
    while (!pq.empty())
    {
        auto [u, d] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist;
}
void solve()
{
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<pair<int, int>> adj[n + 1];
    vector<pair<int, int>> rev_adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    vector<int> dist1 = dijkstra(1, adj);
    vector<int> distn = dijkstra(n, rev_adj);

    int ans = 1e18;
    for (auto &[u, v, w] : edges)
    {
        ans = min(ans, dist1[u] + distn[v] + w / 2);
    }
    cout << ans << endl;
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