// Find the number of unordered ways,
// N can be partitioned into K positive integers (i.e > 0),
// i.e sum of all K numbers must be N.

// Print the answer mod 10^9 + 7.

// For example, N = 7, K = 3,
// then the number of unordered ways are 4.
// Explanation: {1, 5, 1}, {2, 2, 3}, {4, 2, 1}, and {3, 1, 3}.
// Note: {1, 5, 1}, {1, 1, 5} and {5, 1, 1} are treated as the same combination,
// i.e order doesn't matter.
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

ll dp[5001][5001], mod = 1e9 + 7;
ll rec(int n, int k)
{
    if (n == 0)
        return 1;
    if (n < 0 || k == 0)
        return 0;
    auto &ans = dp[n][k];
    if (ans != -1)
        return ans;
    ans = rec(n - k, k);
    (ans += rec(n, k - 1)) %= mod;
    return ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << rec(n - k, k) << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
