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
    int k;
    cin >> k;
    int height[n + 1];
    for (auto &v : height)
        cin >> v;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = inf;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
            }
        }
    }
    cout << dp[n - 1];
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