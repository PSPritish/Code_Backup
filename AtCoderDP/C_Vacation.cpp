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
    int task[n + 1][3];
    for (auto &v : task)
    {
        for (auto &x : v)
        {
            cin >> x;
        }
    }
    int dp[n + 1][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                dp[i][j] = task[i][j];
            }
            else
            {
                if (j == 0)
                {
                    dp[i][0] = max(dp[i - 1][1] + task[i][0], dp[i - 1][2] + task[i][0]);
                }
                else if (j == 1)
                {
                    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
                    dp[i][1] += task[i][1];
                }
                else
                {
                    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
                    dp[i][2] += task[i][2];
                }
            }
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    // cin >> t;

    while (t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}