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
void dijkstra(int src)
{
    dist.assign(n + 1, 1e18);
    visited.assign(n + 1, 0);

    priority_queue<state, vector<state>, p> pq;

    pq.push({src, 0});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto st = pq.top();
        pq.pop();
        int node = st.first, d = st.second;

        if (visited[node])
            continue;
        visited[node] = 1;

        for (auto v : g[node])
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
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

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