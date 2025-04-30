#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

vector<vector<int>> adj;
vector<int> level;
vector<vector<int>> par;
int n, q;

void dfs(int node, int parent, int lvl)
{
    par[node][0] = parent;
    level[node] = lvl;

    for (int i{1}; i <= 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (int child : adj[node])
    {
        if (child != parent)
            dfs(child, node, lvl + 1);
    }
}
int lca(int u, int v)
{
    if (level[u] > level[v])
        swap(u, v); // v is deeper
    while (level[v] > level[u])
    {
        v = par[v][0];
    }
    if (u == v)
        return u; // important

    for (int i{20}; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void solve()
{
    // lowest common ancestor of two nodes in a tree
    cin >> n;
    
    adj.resize(n + 1);
    level.assign(n + 1, 0);
    par.assign(n + 1, vector<int>(21, 0));

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    
    dfs(1, 0, 0);
    while (q--)
    {
        int u, v, z;
        cin >> u >> v >> z;
        int uv = lca(u, v);
        int vp = lca(v, z);
        int up = lca(u, z);
        if (uv == vp)
            cout << up << endl;
        else if (uv == up)
            cout << vp << endl;
        else
            cout << uv << endl;
    }
    adj.clear();
    level.clear();
    par.clear();
    
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