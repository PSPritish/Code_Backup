#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
// data structure
// https://codeforces.com/contest/932/problem/D
// https : // codeforces.com/contest/208/problem/E
// https://codeforces.com/contest/191/problem/C
vector<vector<int>>
    adj;
vector<int> val;
vector<int> level;
vector<vector<int>> par;
void dfs(int node, int parent, int lev)
{
    par[node][0] = parent;
    level[node] = lev;
    for (int i{1}; i <= 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto &v : adj[node])
    {
        if (v != parent)
        {
            dfs(v, node, lev + 1);
        }
    }
}
int lca(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v); // u is deeper
    for (int i{20}; i >= 0; i--)
    {
        if (level[u] - level[v] & (1 << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i{20}; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[v][0];
}
void add(int u, int v, int x)
{
    int l = lca(u, v);
    val[u] += x;
    val[v] += x;
    val[l] -= x;
    val[par[l][0]] -= x;
}
void push_up(int n, int p)
{
    for (auto &v : adj[n])
    {
        if (v != p)
        {
            push_up(v, n);
        }
    }
    val[par[n][0]] += val[n];
}
void solve()
{
    int n, q;
    cin >> n;
    adj.resize(n + 1);
    val.resize(n + 1, 0);
    level.resize(n + 1, 0);
    par.resize(n + 1, vector<int>(21, 0));
    for (int i{1}; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    cin >> q;
    while (q--)
    {
        int u, v, x;
        cin >> u >> v >> x;
        add(u, v, x);
    }
    push_up(1, 0);
    for (int i{1}; i <= n; i++)
    {
        cout << val[i] << " ";
    }
    cout << endl;
    adj.clear();
    level.clear();
    par.clear();
    val.clear();
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