#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define int int64_t
using state = pair<int, int>;
class p
{
public:
    bool operator()(state &p1, state &p2)
    {
        return p1.second > p2.second;
    }
};
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> visited;
vector<int> dist;
vector<pair<state, int>> edges;
void dijkstra(int src)
{
    dist.assign(n + 1, 1e18);
    visited.assign(n + 1, -1);

    priority_queue<state, vector<state>, p> pq;

    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto st = pq.top();
        pq.pop();
        int n = st.first, d = st.second;

        if (visited[n] == 1)
            continue;
        visited[n] = 1;

        for (auto v : g[n])
        {
            if (dist[v.first] > d + v.second)
            {
                dist[v.first] = d + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}
void solve()
{
    cin >> n;
    cin >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edges.push_back({{a, b}, c});
    }
    int a;
    cin >> a;
    dijkstra(a);
    int ans = -1e18;

    for (auto it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        ll d = it.second;

        ans = max(ans, (dist[u] + dist[v] + d) * 5);
    }

    // for(int i = 1; i <= n;i++)
    //  cout<<dist[i];

    cout << ans << endl;
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}