// Given a bracket sequence with ‘?’ at some places, you need to find the number of ways you can replace ‘?’ with ‘(‘ or ‘)’ to form a regular bracket sequence.A bracket sequence is called regular if it is possible to obtain the correct arithmetic expression by inserting characters + and1 into this sequence.
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int dp[1001][1001];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == '(')
            {
                for (int j = 1; j < n; ++j)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
            }
            else if (s[i - 1] == ')')
            {
                for (int j = 0; j < n; ++j)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
            else
            {
                for (int j = 1; j < n; ++j)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
                for (int j = 0; j < n; ++j)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= mod;
                }
            }
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}
