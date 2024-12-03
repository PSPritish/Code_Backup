#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int N = 2e5 + 5;
vector<int> adj[N];
int lv[N];
int par[N][21];
void dfs(int node, int parent, int level)
{
    par[node][0] = parent;
    lv[node] = level;
    for (int i = 1; i < 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto &v : adj[node])
    {
        if (v != parent)
        {
            dfs(v, node, level + 1);
        }
    }
}
int lca(int a, int b)
{
    if (lv[a] > lv[b])
    {
        swap(a, b); // b is deeper
    }
    int diff = lv[b] - lv[a];
    for (int i{19}; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            b = par[b][i];
        }
    }
    if (b == a)
        return b;
    for (int i{19}; i >= 0; i--)
    {
        if (par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}
void solve()
{
    int n;
    cin >> n;
    for (int i{2}; i <= n; i++)
    {
        int temp;
        cin >> temp;
        adj[temp].push_back(i);
    }
    dfs(1, 0, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int u, d;
        cin >> u >> d;
        int cnt = 0;
        for (int i{2}; i <= n; i++)
        {
            if (lv[i] == d and lca(u, i) == u)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
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