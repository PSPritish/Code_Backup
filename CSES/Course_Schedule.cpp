#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> ans;
bool isCycle = false;

void dfs(int u, vector<int> adj[], vector<int> &vis)
{
    if (isCycle)
        return;
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (vis[v] == 1)
        {
            isCycle = true;
            return;
        }
        else if (vis[v] == 0)
        {
            dfs(v, adj, vis);
            if (isCycle)
                return;
        }
    }
    vis[u] = 2;
    ans.push_back(u);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], vis(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis);
        if (isCycle)
            break;
    }
    if (isCycle)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        reverse(ans.begin(), ans.end());
        for (auto &x : ans)
            cout << x << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
