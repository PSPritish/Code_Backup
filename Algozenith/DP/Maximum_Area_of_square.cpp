#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'
vector<vector<int>> arr;
int n, m;
vector<vector<int>> dp;

void solve()
{
    cin >> n >> m;
    arr.assign(n, vector<int>(m, 0));
    dp.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i - 1][j - 1])
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans * ans << endl;
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