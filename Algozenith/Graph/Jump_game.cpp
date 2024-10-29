#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'

class p
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

int n, a, b, d;

vector<int> visited;
vector<int> dist;
vector<vector<pair<int, int>>> graph;

void dijkstra(int src)
{
    dist.assign(n + d + 1, 1e18);
    visited.assign(n + d + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, p> pq;

    dist[src] = 0;
    pq.push({src, dist[src]});

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        if (visited[node.first])
            continue;
        visited[node.first] = 1;

        for (auto &v : graph[node.first])
        {
            if (dist[v.first] > dist[node.first] + v.second)
            {
                dist[v.first] = dist[node.first] + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}

void solve()
{

    cin >> n >> a >> b;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    int src;
    cin >> src;

    graph.resize(n + 1 + mp.size());
    for (int i = 1; i < n; i++)
    {
        graph[i].push_back({i + 1, b});
        graph[i + 1].push_back({i, b});
    }

    int dnode = n + 1;
    d = n + mp.size();
    for (auto &v : mp)
    {
        for (auto &u : v.second)
        {
            graph[dnode].push_back({u, a});
            graph[u].push_back({dnode, 0});
        }
        dnode++;
    }
    dijkstra(src);

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
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
    int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}