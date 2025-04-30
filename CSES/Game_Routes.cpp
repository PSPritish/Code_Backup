#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> back_edges[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        back_edges[v].push_back(u);
    }
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto &v : adj[u])
        {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (auto &x : topo)
    {
        for (auto &v : back_edges[x])
        {
            dp[x] += dp[v];
            dp[x] %= 1000000007;
        }
    }
    cout << dp[n] << endl;
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