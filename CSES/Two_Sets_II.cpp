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
    int max_sum = n * (n + 1) / 2;
    // cerr << max_sum << endl;
    if (max_sum % 2)
    {
        cout << 0;
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int>(max_sum / 2 + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= max_sum / 2; i++)
        {
            dp[j][i] = (dp[j - 1][i] % mod) + ((i >= j) ? dp[j - 1][i - j] : 0) % mod;
            dp[j][i] %= mod;
        }
    }
    cout << dp[n][max_sum / 2];
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