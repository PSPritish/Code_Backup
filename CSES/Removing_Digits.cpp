#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"

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
            return n + 1;
        }
        if (i == 0)
        {
            return 0;
        }
        int &ans = dp[i];
        if (ans != -1)
            return ans;
        ans = n + 1;
        int temp = i;
        vector<int> digits;
        while (temp)
        {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        for (auto &v : digits)
        {
            ans = min(ans, rec(i - v) + 1);
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

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}