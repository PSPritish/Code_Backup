#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'
using state = pair<int, int>;
class p
{
public:
    bool operator()(state &p1, state &p2)
    {
        return p1.second > p2.second;
    }
};
struct edge
{
    int a, b, c;
};
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> visited;

void dijkstra(int src)
{
    int count = n - 1;
    dist.assign(n + 1, 1e18);
    visited.assign(n + 1, 0);

    priority_queue<state, vector<state>, p> pq;
    pq.push({src, 0});
    while (!pq.empty())
    {
        int node = pq.top().first, weight = pq.top().second;

        if (visited[node])
            continue;
        visited[node] = 1;

        for (auto v : g[node])
        {
            if (dist[v.first] > weight + v.second)
            {
                dist[v.first] = weight + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    edge g[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[i].a = a;
        g[i].b = b;
        g[i].c = -c;
    }
    dist.assign(n + 1, 1e18);
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = g[j].a;
            int v = g[j].b;
            int c = g[j].c;
            dist[v] = min(dist[v], dist[u] + c);
        }
    }

    bool neg = false;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].a;
        int v = g[i].b;
        int c = g[i].c;
        if (dist[v] > dist[u] + c)
        {
            neg = true;
            break;
        }
    }

    if (neg)
        cout << "-1\n";
    else
    {
        assert(dist[n] != 1e18);
        cout << -dist[n] << "\n";
    }
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