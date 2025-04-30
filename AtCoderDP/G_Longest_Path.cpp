// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;
vector<vector<int>> adj(100100 + 1);
vector<int> dp(100100 + 1, 0);

int dfs(int x)
{
    if (dp[x])
        return dp[x];
    for (auto &v : adj[x])
    {
        dp[v] = dfs(v);
        dp[x] = max(dp[x], dp[v] + 1);
    }
    return dp[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    ////cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}