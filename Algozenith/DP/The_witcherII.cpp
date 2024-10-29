#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int grid[210][210];
int dp[210][210];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m)), dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dungeon[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j == m - 1 and i == n - 1)
                dp[i][j] = max(1LL, 1 - dungeon[i][j]);
            else
                dp[i][j] = max(1LL, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    cout << dp[0][0] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}