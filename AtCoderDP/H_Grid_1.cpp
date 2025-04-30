#include <bits/stdc++.h>

using namespace std;

bool ok[1000][1000];
long long dp[1000][1000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == '.')
                ok[i][j] = true;
            else
                ok[i][j] = false;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!ok[i][j])
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}