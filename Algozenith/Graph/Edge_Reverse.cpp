#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;

void bfs01(int sc)
{
    dist.assign(n + 1, 1e9);

    deque<int> dq;
    dist[sc] = 0;
    dq.push_back(sc);
    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();
        for (auto v : g[node])
        {

            if (dist[v.first] > dist[node] + v.second)
            {
                dist[v.first] = dist[node] + v.second;
                if (v.second)
                {
                    dq.push_back(v.first);
                }
                else
                    dq.push_front(v.first);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    dist.assign(n + 1, 1e9);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 0});
        g[b].push_back({a, 1});
    }

    bfs01(1);
    cout << ((dist[n] == 1e9) ? -1 : dist[n]) << endl;

    g.clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    while (i--)
        solve();
}