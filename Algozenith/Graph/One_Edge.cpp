#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
vector<vector<int>> g;
vector<int> v;
int temp;
void dfs(int node, int color)
{

    v[node] = color;
    temp++;
    for (auto i : g[node])
    {
        if (!v[i])
            dfs(i, color);
    }
}
void solve()
{
    int n, m;

    cin >> n >> m;
    g.resize(n + 1);
    v.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int color = 0;
    int sqsum = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = 0;
        if (!v[i])
        {
            color++;
            dfs(i, color);
        }
        sqsum += temp * temp;
        sum += temp;
    }
    cout << (sum * sum - sqsum) / 2 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}