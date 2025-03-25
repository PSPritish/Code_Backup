#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
vector<int> adj[200001];
int n;
int dp[200001];
int dis[200001];
int maxdist = 0;
void dfs(int node, int par, int depth = 0)
{
    dp[node] = 1;
    maxdist += depth;
    for (auto &v : adj[node])
    {
        if (v == par)
            continue;
        dfs(v, node, depth + 1);
        dp[node] += dp[v];
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dis[1] = maxdist;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &v : adj[node])
        {
            if (dis[v] == 0)
            {
                dis[v] = dis[node] - dp[v] + dp[1] - dp[v];
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
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