#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'

int n, m;
int go_imedieatly_to[110];
int dist[110], vis[110];

int bfs(int src)
{
    memset(vis, 0, sizeof(vis));

    queue<int> q;

    q.push(src);
    dist[src] = 0;
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int nextnode = go_imedieatly_to[i + node];
            if (nextnode <= 100 and nextnode >= 1 and !vis[nextnode])
            {
                q.push(nextnode);
                vis[nextnode] = 1;
                dist[nextnode] = dist[node] + 1;
            }
        }
    }
    if (!vis[100])
        return -1;
    else
        return dist[100];
}

void solve()
{

    cin >> n;
    for (int i = 1; i <= 100; i++)
        go_imedieatly_to[i] = i;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        go_imedieatly_to[a] = b;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        go_imedieatly_to[a] = b;
    }

    cout << bfs(1) << endl;
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}