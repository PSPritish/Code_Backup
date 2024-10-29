#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
string s1, s2;
int dp[1111][1111];
int rec(int i, int j)
{
    // pruning

    // base case;
    if (i == s1.length() or j == s2.length())
    {
        return 0;
    }
    // cache check
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // transition

    int ans = 0;
    if (s1[i] == s2[j])
    {
        ans = max(ans, rec(i + 1, j + 1) + 1);
    }

    // save and return
    return dp[i][j] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < s1.length(); i++)
        for (int j = 0; j < s2.length(); j++)
            ans = max(ans, rec(i, j));
    cout << ans << endl;
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