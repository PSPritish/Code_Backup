#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<vector<int>> g, par;
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    par.resize(n + 1);
    int dp[n + 1];
    int indeg[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(indeg, 0, sizeof(indeg));
    priority_queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        par[b].push_back(a);
        indeg[b]++;
    }

    dp[1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.top();
        q.pop();
        for (auto v : g[node])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
        for (auto v : par[node])
        {
            dp[node] = (dp[node] + dp[v]) % 1000000007;
        }
    }

    cout << dp[n] << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}