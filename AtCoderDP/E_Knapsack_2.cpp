// Author: P S Pritish
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 1;
constexpr int mx = 1e5 + 7;
void solve()
{
    int n, w;
    cin >> n >> w;
    pair<int, int> item[n + 1];
    for (auto &v : item)
    {
        int a, b;
        cin >> a >> b;
        v = {a, b};
    }
    int dp[mx];
    memset(dp, 1e18, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = mx - 1; j >= 0; j--)
        {
            if (dp[j] + item[i].first <= w)
            {
                dp[j + item[i].second] = min(dp[j + item[i].second], dp[j] + item[i].first);
            }
        }
    }
    for (int i = mx - 1; i >= 0; i--)
    {
        if (dp[i] != 1e18)
        {
            cout << i;
            break;
        }
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
    //  cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}