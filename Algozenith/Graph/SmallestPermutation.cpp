#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"

vector<vector<int>> g;
vector<int> indeg;
vector<int> ans;
int n, m;

void bfs()
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(-i);
    }

    while (!q.empty())
    {
        int n = q.top();
        q.pop();
        ans.push_back(-n);
        for (int v : g[-n])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(-v);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indeg.assign(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b] += 1;
    }

    bfs();
    if ((int)ans.size() == n)
        for (auto v : ans)
            cout << v << ' ';
    else
        cout << -1 << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}