#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int mod = 1e9 + 7;
int n;
int dp[1001000][5];
int rec(int level, int match)
{
    if (match == 4)
    {
        return 0;
    }
    if (level == n)
    {
        return 1;
    }
    if (dp[level][match] != -1)
        return dp[level][match];

    int ans;
    if (match == 0)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 1);
    }
    else if (match == 1)
    {
        ans = (rec(level + 1, 2) % mod + rec(level + 1, 1) % mod) % mod;
    }
    else if (match == 2)
        ans = (rec(level + 1, 3) % mod + rec(level + 1, 0) % mod) % mod;
    else if (match == 3)
        ans = (rec(level + 1, 4) % mod + rec(level + 1, 2) % mod) % mod;
    ans %= mod;
    return dp[level][match] = ans;
}
void solve()
{
    cin >> n;
    // dp.assign(n + 1,vector<int>(5,-1));
    cout << rec(0, 0) % mod << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int a;
    cin >> a;
    while (a--)
        solve();
}