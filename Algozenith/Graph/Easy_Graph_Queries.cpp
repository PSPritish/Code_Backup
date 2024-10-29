#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<vector<int>> g;
vector<int> v;
vector<int> sz;
void dfs(int node, int color)
{
    sz[color]++;
    v[node] = color;
    for (auto i : g[node])
    {
        if (!v[i])
            dfs(i, color);
    }
}
void solve()
{
    int n, m, q;

    cin >> n >> m >> q;
    g.resize(n + 1);
    v.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int color = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            color++;
            dfs(i, color);
        }
    }
    while (q--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int temp;
            cin >> temp;
            cout << sz[v[temp]] << endl;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (v[a] == v[b])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}