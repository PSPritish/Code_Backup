#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
const int MOD = 1e9 + 7;
int n, m;
vector<pair<int, int>> adj[200200];
vector<int> visited, num, minf, maxf, dist;
class p
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    visited.assign(n + 1, -1);
    num.assign(n + 1, 0);
    minf.assign(n + 1, 0);
    maxf.assign(n + 1, 0);
    dist.assign(n + 1, 1e18);

    priority_queue<pair<int, int>, vector<pair<int, int>>, p> pq;

    pq.push({src, 0});
    dist[src] = 0;
    num[src] = 1;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (visited[x.first] != -1)
            continue;
        visited[x.first] = 1;
        for (auto &to : adj[x.first])
        {
            if (dist[to.first] > dist[x.first] + to.second)
            {
                dist[to.first] = dist[x.first] + to.second;
                pq.push({to.first, dist[to.first]});
                num[to.first] = num[x.first];
                minf[to.first] = minf[x.first] + 1;
                maxf[to.first] = maxf[x.first] + 1;
            }
            else if (dist[to.first] == dist[x.first] + to.second)
            {
                (num[to.first] += num[x.first]) %= MOD;
                minf[to.first] = min({minf[to.first], minf[x.first] + 1});
                maxf[to.first] = max({maxf[to.first], maxf[x.first] + 1});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(1);
    if (dist[n] == 1e18)
    {
        cout << -1;
        return;
    }
    cout << dist[n] << " " << num[n] << " " << minf[n] << ' ' << maxf[n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}