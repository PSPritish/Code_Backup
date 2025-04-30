#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n;
vector<int> adj[200100];
int depth[200100];
void dfs(int node, int par, int d)
{
    depth[node] = d;
    for (auto to : adj[node])
    {
        if (to != par)
        {
            dfs(to, node, d + 1);
        }
    }
}
void solve()
{
    int n;
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
        if (depth[maxch] < depth[i])
            maxch = i;
    }
    dfs(maxch, 0, 0);

    for (int i = 1; i <= n; i++)
    {
        if (depth[maxch] < depth[i])
            maxch = i;
    }
    cout << depth[maxch];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int a; cin>>a; while(a--)
    solve();
}