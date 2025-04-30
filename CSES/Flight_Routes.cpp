#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int n, m, k;
const int INF = 2e5 + 5;
vector<pair<int, int>> adj[INF];
priority_queue<int> bes[INF];
struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({src, 0});
    bes[src].push(0);
    while (!pq.empty())
    {
        auto [u, d] = pq.top();
        pq.pop();
        if (bes[u].top() < d)
            continue;

        for (auto &[v, w] : adj[u])
        {
            int temp = d + w;
            if (bes[v].size() < k)
            {
                bes[v].push(temp);
                pq.push({v, temp});
            }
            else if (bes[v].top() > temp)
            {
                bes[v].pop();
                bes[v].push(temp);
                pq.push({v, temp});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijstra(1);
    vector<int> ans;
    while (!bes[n].empty())
    {
        ans.push_back(bes[n].top());
        bes[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
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