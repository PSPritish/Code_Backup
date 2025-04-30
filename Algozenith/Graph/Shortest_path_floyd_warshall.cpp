#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    long long dist[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = 1e18;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[b][a] = dist[a][b] = min(dist[a][b], c * 1LL);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << ((dist[a][b] == 1e18) ? -1 : dist[a][b]) << endl;
    }
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
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
}