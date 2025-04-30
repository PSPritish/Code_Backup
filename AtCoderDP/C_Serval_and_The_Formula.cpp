#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// We will work with up to L bits (enough to cover x,y up to 1e9 and k up to 1e18)
const int L = 62;

// We'll use memoization: dp[i][c1][c2] = answer for bits from i onward with given carries for x and y.
// If no solution exists, we store -2 (since -1 is a valid output flag).
ll dp[65][2][2];
bool vis[65][2][2];

ll x, y;

// Returns a valid k (as a number) from bit i onward (i = LSB index) given carries c1 (for x) and c2 (for y).
// Returns -1 if no valid k exists.
ll solve_dp(int i, int c1, int c2)
{
    if (i == L)
    {
        // At the end, we must have no leftover carry.
        if (c1 == 0 && c2 == 0)
            return 0;
        else
            return -1;
    }
    if (vis[i][c1][c2])
        return dp[i][c1][c2];
    vis[i][c1][c2] = true;
    ll res = -1;
    // Get bit i for x and y.
    int bitx = (x >> i) & 1;
    int bity = (y >> i) & 1;

    // Try both possibilities for k's bit: 0 or 1.
    for (int kbit = 0; kbit < 2; kbit++)
    {
        int sumx = bitx + kbit + c1;
        int outx = sumx & 1;
        int nc1 = sumx >> 1;

        int sumy = bity + kbit + c2;
        int outy = sumy & 1;
        int nc2 = sumy >> 1;

        // Condition: we cannot have both output bits 1.
        if (outx == 1 && outy == 1)
            continue;

        ll rec = solve_dp(i + 1, nc1, nc2);
        if (rec == -1)
            continue;

        // If we found a valid assignment for higher bits, add current bit to answer.
        res = rec + ((ll)kbit << i);
        break; // We can output any valid answer.
    }
    dp[i][c1][c2] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        // Special case: if x==y then for any k, (x+k) == (y+k) and their AND is the same number.
        // Since x+y+2k > 0 for any k>=0, the equation cannot hold.
        if (x == y)
        {
            cout << -1 << "\n";
            continue;
        }

        // Reset memoization arrays.
        memset(vis, 0, sizeof(vis));
        ll ans = solve_dp(0, 0, 0);
        // Make sure k is within required bounds (0 <= k <= 1e18)
        if (ans < 0 || ans > 1000000000000000000LL)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
