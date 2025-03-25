#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int mod = 1e9 + 7;

void solve()
{
    int mod = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    vector<int> x(n);
    for (int &v : x)
        cin >> v;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if (left >= 0)
            {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][target] << endl;
    // function<int(int, int)> rec = [&](int i, int req) -> int
    // {
    //     if (req == 0)
    //         return 1; // Base case: one way to make 0 sum
    //     if (req < 0 || i == n)
    //         return 0; // Prevent negative access

    //     int &ans = dp[i][req];
    //     if (ans != -1)
    //         return ans;
    //     ans = 0;

    //     ans = (rec(i, req - coin[i]) + rec(i + 1, req)) % mod;

    //     return ans;
    // };

    // int ans = rec(0, x);
    // cout << ans << endl;
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}
