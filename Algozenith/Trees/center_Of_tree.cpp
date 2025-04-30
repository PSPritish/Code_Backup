#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n;
vector<int> adj[200200];
int depth[200200];
int parent[200200];
void dfs(int v, int par, int d)
{
    depth[v] = d;
    parent[v] = par;
    for (auto to : adj[v])
    {
        if (to != par)
        {
            dfs(to, v, d + 1);
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    int maxch = 1;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > depth[maxch])
            maxch = i;
    }
    dfs(maxch, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > depth[maxch])
            maxch = i;
    }
    if (depth[maxch] % 2 == 0)
    {
        int ans = maxch;
        for (int i = 0; i < depth[maxch] / 2; i++)
        {
            ans = parent[ans];
        }
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}