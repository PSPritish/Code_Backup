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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        back_edges[b].push_back(a);
    }
    vector<int> dp(n + 1, INT_MIN);
    vector<int> in_degree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            in_degree[x]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto x : adj[u])
        {
            in_degree[x]--;
            if (in_degree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    vector<int> parent(n + 1, -1);
    dp[1] = 1;
    for (int i = 0; i < topo.size(); i++)
    {
        int x = topo[i];
        for (auto &y : back_edges[x])
        {
            if (dp[x] < dp[y] + 1)
            {
                dp[x] = dp[y] + 1;
                parent[x] = y;
            }
        }
    }
    if (dp[n] < 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dp[n] << endl;
    vector<int> ans;
    int cur = n;
    while (parent[cur] != -1)
    {
        ans.push_back(cur);
        cur = parent[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << " ";
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