#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    string grid[n];
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int dp[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = (grid[i][j] != '*') ? 1 : 0;
            }
            else if (grid[i][j] != '*')
            {
                dp[i][j] = 0;
                if (i > 0)
                    dp[i][j] += dp[i - 1][j] % mod;
                if (j > 0)
                    dp[i][j] += dp[i][j - 1] % mod;

                dp[i][j] %= mod;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][n - 1];
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}