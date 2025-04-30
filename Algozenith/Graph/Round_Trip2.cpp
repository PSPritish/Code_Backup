#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int n, m;
vector<vector<int>> g;
vector<int> visited;
bool flag;
void dfs(int node)
{
    if (flag)
        return;
    visited[node] = 1;
    for (auto v : g[node])
    {
        if (visited[v] == 1)
        {
            flag = true;
            return;
        }
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }
    visited[node] = 2;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    visited.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    if (flag)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";

    g.clear();
    visited.clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}