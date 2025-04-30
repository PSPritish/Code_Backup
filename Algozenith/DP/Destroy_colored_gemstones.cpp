#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int n;
int dp[110][110];
int s[110];
int rec(int l, int r)
{
    if (l > r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1e9;
    ans = min(ans, 1 + rec(l + 1, r));

    if (l + 1 <= r and s[l] == s[l + 1])
    {
        ans = min(ans, 1 + rec(l + 2, r));
    }
    for (int i = l + 2; i <= r; i++)
    {

        if (s[l] == s[i])
        {
            ans = min(ans, rec(l + 1, i - 1) + rec(i + 1, r));
        }
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    while (a--)
        solve();
}