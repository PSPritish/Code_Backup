#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n, m;
vector<vector<int>> r;
vector<bool> visited;
int ans;
void bfs(int node)
{
    queue<int> q;
    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int cr_node = q.front();
        q.pop();

        for (auto v : r[cr_node])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    r.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans++;
            bfs(i);
        }
    }
    cout << ans - 1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}