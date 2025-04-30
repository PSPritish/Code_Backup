#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        adj[i + 1].push_back(a);
    }
    int parent[n + 1][31];
    memset(parent, 0, sizeof(parent));

    for (int i = 1; i <= n; i++)
    {
        parent[i][0] = adj[i][0];
    }
    for (int d = 1; d <= 30; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i <= 30; i++)
        {
            if (k & (1 << i))
            {
                x = parent[x][i];
            }
        }
        cout << x << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}