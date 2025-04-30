#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
int n, q;
vector<int> val;
vector<vector<int>> adj;
vector<int> level;
vector<vector<int>> par;
vector<vector<int>> dp;

void dfs(int node, int parent, int lev)
{
    par[node][0] = parent;
    level[node] = lev;
    dp[node][0] = __gcd(val[node], val[parent]);
    for (int i{1}; i <= 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
        dp[node][i] = __gcd(dp[node][i - 1], dp[par[node][i - 1]][i - 1]);
    }
    for (auto v : adj[node])
    {
        if (v != parent)
            dfs(v, node, lev + 1);
    }
}
int lca(int u, int v)
{
    if (level[u] < level[v])
    { // u is deeper
        swap(u, v);
    }
    int ans = __gcd(val[u],val[v]); // zero can be replaced by identity element
    for (int i{20}; i >= 0; i--)
    {
        if (level[u] - level[v] & (1 << i))
        {

            ans = __gcd(ans, dp[u][i]);
            u = par[u][i];
        }
    }
    if (u == v)
    {
        return ans;
    }
    for (int i{20}; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {

            ans = __gcd(ans, dp[u][i]);
            ans = __gcd(ans, dp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    ans = __gcd(ans, val[par[u][0]]);
    return ans;
}
void solve()
{
    cin >> n;
    val.resize(n + 1);
    adj.resize(n + 1);
    level.assign(n + 1, 0);
    par.assign(n + 1, vector<int>(21, 0));
    dp.assign(n + 1, vector<int>(21, 0));

    for (int i{1}; i <= n; i++)
        cin >> val[i];
    for (int i{1}; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    val[0] = 1;
    dfs(1, 0, 0);
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    adj.clear();
    val.clear();
    level.clear();
    par.clear();
    dp.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}