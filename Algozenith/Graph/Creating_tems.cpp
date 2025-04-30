#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
using state = pair<int, int>;
vector<vector<int>> r;
vector<int> visited;

int is_possible = 0;

void dfs(int node, int prev_col)
{

    visited[node] = 3 - prev_col;

    for (auto v : r[node])
    {
        if (visited[v] == -1)
        {
            dfs(v, visited[node]);
        }
        else if (visited[v] == visited[node])
            is_possible++;
    }
}
void solve()
{

    int n, m;
    cin >> n >> m;

    r.resize(n + 1);
    visited.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == -1)
            dfs(i, 1);
    }

    if (!is_possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int i; cin>>i; while(i--)
    solve();
}