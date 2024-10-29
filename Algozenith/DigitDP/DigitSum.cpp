#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define endl "\n"
string s, t;
int d;
int dp[10010][2][2][110];
const int mod = 1e9 + 7;
int rec(int level, int tlo, int thi, int sum)
{
    if (level == s.size())
    {
        if (sum % d == 0)
            return 1;
        return 0;
    }

    int &ans = dp[level][tlo][thi][sum];
    if (ans != -1)
        return ans;
    int hi = 9;
    int lo = 0;
    if (tlo == 1)
    {
        lo = t[level] - '0';
    }
    if (thi == 1)
    {
        hi = s[level] - '0';
    }
    ans = 0;
    for (int i = lo; i <= hi; i++)
    {
        ans += rec(level + 1, tlo & (i == lo), thi & (i == hi), (sum + i) % d);
        ans %= mod;
    }
    return ans;
}
void solve()
{
    cin >> s >> d;
    memset(dp, -1, sizeof dp);
    t = "";
    int c = s.size() - 1;
    while (c--)
        t += '0';
    t = t + '1';
    cout << rec(0, 1, 1, 0) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        solve();
}