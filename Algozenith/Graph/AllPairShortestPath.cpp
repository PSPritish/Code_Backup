#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int dist[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }
    int x[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    vector<int> ans;
    for (int k = n; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][x[k]] + dist[x[k]][j], dist[i][j]);
        }
        int temp = 0;
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= n; j++)
            {
                temp += dist[x[i]][x[j]];
            }
        }
        ans.push_back(temp);
    }

    reverse(ans.begin(), ans.end());
    for (auto &v : ans)
        cout << v << ' ';
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