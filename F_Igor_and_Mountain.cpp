#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }

        // Precompute L = floor(sqrt(d*d - 1)).
        int L = 0;
        if (d * d - 1 >= 0)
            L = (int)floor(sqrt(d * 1LL * d - 1));

        // dp[r][j]: number of ways for rows r..0 (r down to top) if the pattern on row r ends at column j.
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Process the bottom row (row n-1). Note grid is given top-to-bottom, so bottom is grid[n-1]
        int r = n - 1;
        // Build prefix sum for holds on bottom row.
        vector<int> pref(m + 1, 0);
        for (int j = 0; j < m; j++)
        {
            pref[j + 1] = pref[j] + (grid[r][j] == 'X');
        }
        for (int k = 0; k < m; k++)
        {
            if (grid[r][k] == 'X')
            {
                int lo = max(0, k - d);
                int hi = min(m - 1, k + d);
                dp[r][k] = (pref[hi + 1] - pref[lo]) % MOD;
            }
            else
            {
                dp[r][k] = 0;
            }
        }

        // Process rows upward from bottom row to the top row.
        // r iterates from n-1 downto 1, and we compute dp[r-1]
        for (int r = n - 1; r >= 1; r--)
        {
            // Compute S[j] = sum_{c in [max(0, j-L), min(m-1, j+L)]} dp[r][c]
            vector<int> S(m, 0);
            vector<int> pref_dp(m + 1, 0);
            for (int c = 0; c < m; c++)
            {
                pref_dp[c + 1] = (pref_dp[c] + dp[r][c]) % MOD;
            }
            for (int j = 0; j < m; j++)
            {
                int lo = max(0, j - L);
                int hi = min(m - 1, j + L);
                S[j] = (pref_dp[hi + 1] - pref_dp[lo]) % MOD;
                if (S[j] < 0)
                    S[j] += MOD;
            }

            // For row r-1, we want dp[r-1][k] = sum_{j in [max(0, k-d), min(m-1, k+d)] with grid[r-1][j]=='X'} S[j]
            vector<int> new_dp(m, 0);
            // Build array T: T[j] = S[j] if grid[r-1][j]=='X', else 0.
            vector<int> T(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (grid[r - 1][j] == 'X')
                {
                    T[j] = S[j];
                }
                else
                {
                    T[j] = 0;
                }
            }
            // Build prefix sum for T.
            vector<int> pref_T(m + 1, 0);
            for (int j = 0; j < m; j++)
            {
                pref_T[j + 1] = (pref_T[j] + T[j]) % MOD;
            }
            for (int k = 0; k < m; k++)
            {
                if (grid[r - 1][k] == 'X')
                {
                    int lo = max(0, k - d);
                    int hi = min(m - 1, k + d);
                    new_dp[k] = (pref_T[hi + 1] - pref_T[lo]) % MOD;
                    if (new_dp[k] < 0)
                        new_dp[k] += MOD;
                }
                else
                {
                    new_dp[k] = 0;
                }
            }

            dp[r - 1] = new_dp;
        }

        // The answer is the sum of dp[0][k] for every column k on the top row (row 0).
        int ans = 0;
        for (int k = 0; k < m; k++)
        {
            ans = (ans + dp[0][k]) % MOD;
        }

        cout << ans % MOD << "\n";
    }
    return 0;
}
