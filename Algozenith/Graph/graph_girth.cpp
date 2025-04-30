#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
int n, m;
vector<vector<int>> g;
vector<int> d;
int ans;

void bfs(int st_node)
{
    queue<int> q;
    d.assign(n + 1, 1e9);

    q.push(st_node);
    d[st_node] = 0;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (auto v : g[n])
        {
            if (d[v] == 1e9)
            {
                q.push(v);
                d[v] = d[n] + 1;
            }
            else if (d[n] <= d[v])
            {
                ans = min(ans, d[n] + d[v] + 1);
                if (d[n] == d[v])
                    return;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 1e9;
    for (int i = 1; i <= n; i++)
    {

        bfs(i);
    }

    cout << ((ans == 1e9) ? -1 : ans);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}