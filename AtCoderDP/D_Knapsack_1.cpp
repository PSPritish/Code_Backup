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
    int n, w;
    cin >> n >> w;
    pair<int, int> item[n + 1];
    for (auto &v : item)
    {
        int a, b;
        cin >> a >> b;
        v = {a, b};
    }
    int dp[w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = w; j >= item[i].first; j--)
        {
            int left = j - item[i].first;
            if (left >= 0)
                dp[j] = max(dp[j], item[i].second + dp[left]);
        }
    }
    cout << dp[w];
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