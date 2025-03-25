#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;
// int dp[1001000][2];
void solve()
{
    int n = 1e6 + 10;
    int q;
    cin >> q;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][0]) % mod;
        dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
    while (q--)
    {
        int a;
        cin >> a;
        cout << (dp[a][0] + dp[a][1]) % mod << endl;
    }
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    // cin >> t;
    // memset(dp, 0, sizeof(dp));
    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}