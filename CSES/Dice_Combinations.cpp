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
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    function<int(int)> rec = [&](int i) -> int
    {
        if (i < 0)
        {
            return 0;
        }

        if (i == 0)
        {
            return 1;
        }

        auto &ans = dp[i];
        if (ans != -1)
        {
            return ans;
        }
        ans = 0;
        for (int v = 1; v <= 6; v++)
        {
            ans += rec(i - v);
            ans %= mod;
        }
        return ans;
    };
    cout << rec(n);
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
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}