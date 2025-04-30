#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl '\n'
int grid[210][210];
int dp[210][210][410];
int n, m, k;
const int mod = 1e9 + 7;

int rec(int i, int j, int left)
{
    // pruning

    // base case
    if (left < 0)
    {
        return 0;
    }
    if (i == n - 1 and j == m - 1)
    {
        if (grid[i][j] == 0 or left > 0)
            return 1;
        return 0;
    }
    if (i == n or j == m)
        return 0;
    // cache check
    if (dp[i][j][left] != -1)
        return dp[i][j][left];
    // transition
    int ans = 0;
    if (grid[i][j] == 0)
    {
        ans = ((rec(i + 1, j, left) % mod + rec(i, j + 1, left) % mod) % mod);
    }
    else
        ans = ((rec(i + 1, j, left - 1) % mod + rec(i, j + 1, left - 1) % mod) % mod);
    // save and return
    return dp[i][j][left] = ans % mod;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int x = 0; x <= k; x++)
                dp[i][j][x] = -1;
        }
    }
    cout << rec(0, 0, k) << endl;
}
signed main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
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