// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;

void solve()
{
    int n;
    cin >> n;
    vector<double> prob(n);
    for (int i = 0; i < n; i++)
        cin >> prob[i];
    int leasthead = n / 2 + 1;
    vector<vector<double>> dp(n + 1, vector<double>(leasthead + 1, 0));
    // memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= leasthead; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1.0 - prob[i - 1]);
        }
    }
    cout << fixed << setprecision(10) << dp[n][leasthead] << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    ////cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}