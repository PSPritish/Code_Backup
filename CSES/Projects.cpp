#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
const int INF = 1000000000;
void solve()
{
    int n;
    cin >> n;
    pair<int, pair<int, int>> arr[n];
    for (int i = 0; i < n; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        arr[i] = make_pair(l, make_pair(r, w));
    }
    sort(arr, arr + n);

    int dp[n + 1];

    for (int i = n; i >= 0; i--)
    {
        if (i == n)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            int r = arr[i].second.first;
            auto it = upper_bound(arr, arr + n, make_pair(r, make_pair(INF, INF))) - arr;
            dp[i] = max(dp[i], dp[it] + arr[i].second.second);
        }
    }
    cout << dp[0];
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