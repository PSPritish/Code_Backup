#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

void solve()
{

    int n, x;
    cin >> n >> x;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    int dp[x + 1];
    memset(dp, -1, sizeof(dp));
    function<int(int)> rec = [&](int req) -> int
    {
        if (req < 0)
        {
            return 1e18;
        }
        if (req == 0)
        {
            return 0;
        }
        int &ans = dp[req];
        if (ans != -1)
            return ans;
        ans = 1e18;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, rec(req - coin[i]) + 1);
        }
        return ans;
    };
    int ans = rec(x);
    if (ans >= 1e18)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
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